
#include "Czujnik_wilgotnosci.h"

Czujnik_wilgotnosci::Czujnik_wilgotnosci(int wire_pin) :
pin(wire_pin), 
humidity(0),
last_humidity(-1),
sensor(wire_pin, DHT11) 
{  
	saved_time = millis();
	refresh_time = 2000;
	blocked = false;

	sensor.begin();
	//humidity = sensor.readHumidity();
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

void Czujnik_wilgotnosci::print_data(LiquidCrystal* lcd, bool screen_change)
{
	if(humidity != last_humidity || screen_change)
	{
		lcd->clear();
		lcd->print(sensor.readHumidity());
		lcd->print("% RH");
		last_humidity = humidity;
	}

	return;
}

void Czujnik_wilgotnosci::execute_task()
{
	unsigned long actual_time = millis();
  
	if(actual_time - saved_time >= refresh_time)
	{		
		humidity = sensor.readHumidity();
		
		saved_time = millis();
	}
	return;
}
