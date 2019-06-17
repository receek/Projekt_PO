#include "Buzzer.h"

Buzzer::Buzzer(int out):
pin(out), 
value(128), 
last_value(-1), 
pushed(false), 
remote(false), 
buzzing(false), 
modyfing(false)
{  
	saved_time = millis();
	refresh_time = 50;
	blocked = false;

	pinMode(out, OUTPUT);
	analogWrite(out, 0);

}


void Buzzer::up_state(bool state)
{
	if(state && value < 255)
	{
		value += 1;
	}
}

void Buzzer::down_state(bool state)
{
	if(state && value > 0)
	{
		value -= 1;
	}
}

void Buzzer::apply_state(bool state)
{
	if(remote && pushed)
	{
		remote = false;
	}
 	else if(state && !pushed)
 	{
 		pushed = true;
 		modyfing = true;
 	}
 	else if(!state && pushed)
 	{
 		pushed = false;
 		modyfing = false;
 	}
}

void Buzzer::choose_state(bool state)
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
}

bool Buzzer::is_modyfing()
{
	return modyfing;
}

bool Buzzer::is_tasking()
{
	return true;
}

void Buzzer::print_data(LiquidCrystal* lcd, bool screen_change)
{
	if(last_value != value || screen_change)
	{
		lcd->clear();
		lcd->print("Buzzer: ");
		lcd->print(value);

		if(modyfing)
		{
			lcd->setCursor(0, 1);
			lcd->print("Changing value!");
		}

		last_value = value;
	}
	
	return;
}

void Buzzer::execute_task()
{
	unsigned long actual_time = millis();
  	
  	if(actual_time - saved_time >= refresh_time)
  	{	
  		if((pushed || remote) && !buzzing)
		{
			buzzing = true;
			analogWrite(pin, value);
			
		}
		else if(remote && buzzing)
		{
			analogWrite(pin, value);
		}
  		else if(!pushed && !remote && buzzing)
		{
			buzzing = false;
			analogWrite(pin, 0);
		}
		
		value != last_value;
		saved_time = millis();
	}
	return;
}

void Buzzer::write_info(char* buffer, int* i)
{
	copy_str("BUZ\n", 4, buffer, *i);
	*i += 4;
}

int Buzzer::write_data(char* buffer)
{
	int size = int_to_char(buffer, value, 0);
	buffer[size] = '\n';

	return size + 1;

}

int Buzzer::procces_data(char* send_buff, char* recv_buff, int pos)
{
	int size = 0;
	if(compare_str("CHN", recv_buff, pos, 3))
	{
		pos += 4;

		int  v = char_to_int(recv_buff, &pos, '\n');
		
		if(v >= 0 && v <= 255)
		{
			value = v;
			if(buzzing) remote = true;
		}
	}
	else if(compare_str("STR", recv_buff, pos, 3))
	{
		remote = true;
	}
	else if(compare_str("STP", recv_buff, pos, 3))
	{
		remote = false;	
	}

	copy_str("OK\n", 3, send_buff, 0);
	size = 3;

	return size;
	
}