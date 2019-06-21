#include "RGB_led.h"

RGB_led::RGB_led(int p[]):
modyfing(-1),
active(true),
remote(false)
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

	if(state)
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
		modyfing++;
	}
	else if(modyfing == 2)
	{
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

bool RGB_led::is_tasking()
{
	return true;
}

void RGB_led::print_data(LiquidCrystal* lcd, bool screen_change)
{
	if(modyfing < 0)
	{
		if(screen_change || remote)
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
	if(active && remote)
	{
		for(int i = 0; i < 3; i++)
		{
			analogWrite(pins[i], 255 - value[i]);
		}

		remote = false;
	}
}

void RGB_led::write_info(char* buffer, int* i)
{
	copy_str("RGB\n", 4, buffer, *i);
	*i += 4;
}


int RGB_led::write_data(char* buffer)
{
	int size = int_to_char(buffer, value[0], 0);
	buffer[size++] = '\n';
	size = int_to_char(buffer, value[1], size);
	buffer[size++] = '\n';
	size = int_to_char(buffer, value[2], size);
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

int RGB_led::procces_data(char* send_buff, char* recv_buff, int pos)
{
	int size = 0;
	if(compare_str("CHN", recv_buff, pos, 3))
	{
		pos += 4;

		int  v = char_to_int(recv_buff, &pos, ' ');

		if(v >= 0 && v <= 255)
		{
			value[0] = v;
		}

		v = char_to_int(recv_buff, &pos, ' ');
		
		if(v >= 0 && v <= 255)
		{
			value[1] = v;
		}

		v = char_to_int(recv_buff, &pos, '\n');
		
		if(v >= 0 && v <= 255)
		{
			value[2] = v;
		}

		remote = true;
	}
	else if(compare_str("STR", recv_buff, pos, 3))
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
