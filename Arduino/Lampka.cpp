#include "Lampka.h"

Lampka::Lampka(int in, int out):
pin_analog_in(in),
pin_pwm(out),
value(analogRead(in)),
last_value(-1),
range(200),
active(true) 
{  
	saved_time = millis();
	refresh_time = 150;
	blocked = false;

	pinMode(pin_pwm, OUTPUT);
}

void Lampka::apply_state(bool state)
{
 	if(!blocked && state)
	{
		if(active)
		{
			active = false;
			analogWrite(pin_pwm, 0);
		}
		else
		{
			active = true;
			if(value <= range)
			{
				double lighting;
				lighting = 255 * (1024 - value) / 1024;
				analogWrite(pin_pwm, lighting);
			}
		}
		delay(500);
	}
}

bool Lampka::is_modyfing()
{
	return false;
}

bool Lampka::is_tasking()
{
	return true;
}

void Lampka::print_data(LiquidCrystal* lcd, bool screen_change)
{
	if(last_value != value || screen_change)
	{
		lcd->clear();
		lcd->print("Light: ");
		lcd->print(double(value) / 1024 * 100);
		lcd->print("%");

		last_value = value;
	}
	
	return;
}

void Lampka::execute_task()
{
	unsigned long actual_time = millis();
  	
  	if(actual_time - saved_time >= refresh_time)
  	{	
  		float lighting;

  		value = analogRead(pin_analog_in);

  		lighting = 255 * (1024 - value) / 1024;

  		if(active && value <= range)
  		{
  			analogWrite(pin_pwm, double(255) - (double(255) * (double(value) / range)));	
  		}
  		else if(last_value != value && last_value <= range)
  		{
  			analogWrite(pin_pwm, 0);	
  		}
  		
	
		saved_time = millis();
	}
	return;
}

void Lampka::write_info(char* buffer, int* i)
{
	copy_str("LAM\n", 4, buffer, *i);
	*i += 4;
}

int Lampka::write_data(char* buffer)
{
	int size = int_to_char(buffer, value, 0);
	buffer[size++] = '\n';
	if(active)
	{
		copy_str("ON", 2, buffer, size);
		size += 2;
	}
	else
	{
		copy_str("OFF", 3, buffer, size);
		size += 3;
	}

	buffer[size++] = '\n';

	return size;

}

int Lampka::procces_data(char* send_buff, char* recv_buff, int pos)
{
	int size = 0;
	if(compare_str("STR", recv_buff, pos, 3))
	{
		if(!active) apply_state(true);
	}
	else if(compare_str("STP", recv_buff, pos, 3))
	{
		if(active) apply_state(true);
	}

	copy_str("OK\n", 3, send_buff, 0);
	size = 3;

	return size;
}

