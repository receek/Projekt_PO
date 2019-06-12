
#include "Czujnik_temperatury.h"

Czujnik_temperatury::Czujnik_temperatury(int wire_pin, uint8_t addr[]) :
pin(wire_pin),
temperature(0),
wire(wire_pin),
sensor(&wire)
{  
	saved_time = millis();
	refresh_time = 2000;
	blocked = false;

	for(int i = 0; i < 8; i++)
	{
		address[i] = addr[i];
	}

	sensor.begin();
	last_temp = -128;
	
}

/*
void Czujnik_temperatury::up_pushed()
{
	
}

void Czujnik_temperatury::down_pushed()
{
  
}

void Czujnik_temperatury::apply_pushed()
{
  
}

void Czujnik_temperatury::choose_pushed()
{
  
}

bool Czujnik_temperatury::is_modyfing()
{
	return false;
}*/

void Czujnik_temperatury::print_data(LiquidCrystal* lcd, bool screen_change)
{
	
	if(temperature != last_temp || screen_change)
	{
		lcd->clear();
		lcd->print("Temp: ");
		lcd->print(temperature);
		last_temp = temperature;
	}

	return;
}

void Czujnik_temperatury::execute_task()
{
	unsigned long actual_time = millis();
  
	if(actual_time - saved_time >= refresh_time)
	{		
		sensor.requestTemperaturesByAddress(address);
		temperature = sensor.getTempC(address);

		saved_time = millis();
	}
	return;
}
