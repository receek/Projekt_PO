#include "Lampka.h"

Lampka::Lampka(int in, int out):
pin_analog_in(in),
pin_pwm(out),
value(analogRead(in)),
last_value(-1),
active(true) 
{  
	saved_time = millis();
	refresh_time = 50;
	blocked = false;

	pinMode(pin_pwm, OUTPUT);

}


/*void Lampka::up_state(bool state)
{
	if(state && value < 255)
	{
		value += 1;
	}
}

void Lampka::down_state(bool state)
{
	if(state && value > 0)
	{
		value -= 1;
	}
}*/

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
			float lighting;
			lighting = 255 * (1024 - value) / 1024;;
			analogWrite(pin_pwm, lighting);
		}
		delay(500);
	}
}

/*void Lampka::choose_state(bool state)
{
	if(modyfing)
	{
		blocked = false;
		modyfing = false;
	}
	else
	{
		blocked = true;
		modyfing = true;
	}
}*/

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
		lcd->print(double(255) * (double(value) / 1024));

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

  		if(active && value <= 200)
  		{
  			analogWrite(pin_pwm, double(255) - (double(255) * (double(value) / 100)));	
  		}
  		else if(last_value != value && last_value <= 200)
  		{
  			analogWrite(pin_pwm, 0);	
  		}
  		
	
		saved_time = millis();
	}
	return;
}
