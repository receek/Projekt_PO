#include "Buzzer.h"

Buzzer::Buzzer(int out):
pin(out), value(128), last_value(-1), pushed(false), buzzing(false), modyfing(false)
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
 	if(state && !pushed)
 	{
 		pushed = true;
 	}
 	else if(!state && pushed)
 	{
 		pushed = false;
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

void Buzzer::print_data(LiquidCrystal* lcd, bool screen_change)
{
	//lcd->clear();
	//	lcd->print("Buzzer: ");
	//	delay(3000);
	if(last_value != value || screen_change)
	{
		lcd->clear();
		lcd->print("Buzzer: ");
		lcd->print(value);
		//delay(3000);

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
  		if(pushed && !buzzing)
		{
			buzzing = true;
			analogWrite(pin, value);
		}
  		else if(!pushed && buzzing)
		{
			buzzing = false;
			analogWrite(pin, 0);
		}
	
		saved_time = millis();
	}
	return;
}
