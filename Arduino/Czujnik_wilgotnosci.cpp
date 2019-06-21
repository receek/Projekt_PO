
#include "Czujnik_wilgotnosci.h"

Czujnik_wilgotnosci::Czujnik_wilgotnosci(int wire_pin) :
pin(wire_pin), 
humidity(0),
last_humidity(-1),
sensor(wire_pin, DHT11) 
{  
	saved_time = millis();
	refresh_time = 2000;

	sensor.begin();
}
void Czujnik_wilgotnosci::print_data(LiquidCrystal* lcd, bool screen_change)
{
	if(humidity != last_humidity || screen_change)
	{
		lcd->clear();
		lcd->print(humidity);
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

void Czujnik_wilgotnosci::write_info(char* buffer, int* i)
{
	copy_str("CZW\n", 4, buffer, *i);
	*i += 4;
}

int Czujnik_wilgotnosci::write_data(char* buffer)
{
	execute_task();
	int size = int_to_char(buffer, humidity, 0);;
	buffer[size] = '\n';

	return size + 1;
}
