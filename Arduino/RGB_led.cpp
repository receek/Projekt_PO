#include "RGB_led.h"

RGB_led::RGB_led(int p[]):
modyfing(-1), active(true)
{  
	for(int i = 0; i < 3; i++)
	{
		pins[i] = p[i];
		value[i] = 128;
		last_value[i] = -1;
		pinMode(pins[i], OUTPUT);
		analogWrite(pins[i], value[i]);
	}

	saved_time = millis();
	refresh_time = 500;
	blocked = false;

}


void RGB_led::up_state(bool state)
{
	if(state && value[modyfing] < 255)
	{
		value[modyfing] += 1;
		if(active) analogWrite(pins[modyfing], 255 - value[modyfing]);
	}
}

void RGB_led::down_state(bool state)
{
	if(state && value[modyfing] > 0)
	{
		value[modyfing] -= 1;
		if(active) analogWrite(pins[modyfing], 255 - value[modyfing]);
	}
}

void RGB_led::apply_state(bool state)
{

	if(!blocked && state)
	{
		if(active)
		{
			active = false;
			for(int i = 0; i < 3; i++)
			{
				analogWrite(pins[i], 255);
			}
		}
		else
		{
			active = true;
			for(int i = 0; i < 3; i++)
			{
				analogWrite(pins[i], 255 - value[i]);
			}
		}
		delay(500);
	}

}


void RGB_led::choose_state(bool state)
{
	if(modyfing < 0)
	{
		blocked = true;
		modyfing++;
	}
	else if(modyfing == 2)
	{
		blocked = false;
		modyfing = -1;
	}
	else
	{
		modyfing++;
	}
}

bool RGB_led::is_modyfing()
{
	return modyfing >= 0;
}

void RGB_led::print_data(LiquidCrystal* lcd, bool screen_change)
{
	if(modyfing < 0)
	{
		// obsługa dla ethernet
		if(screen_change)
		{
			lcd->clear();
			lcd->print("R:");
			lcd->print(value[0]);
			lcd->print(" G:");
			lcd->print(value[1]);
			lcd->setCursor(0, 1);
			lcd->print("B:");
			lcd->print(value[2]);
		}
	}
	else if(last_value[modyfing] != value[modyfing] || screen_change)
	{
		char letter[] = {"RGB"};

		lcd->clear();
		lcd->print(letter[modyfing]);
		lcd->print(":");
		lcd->print(value[modyfing]);

		last_value[modyfing] = value[modyfing];
	}
	
	return;
}

void RGB_led::execute_task()
{
	return;
}
