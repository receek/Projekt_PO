
#include "Czujnik_odleglosci.h"

Czujnik_odleglosci::Czujnik_odleglosci(int epin, int tpin):
echo_pin(epin),
trig_pin(tpin),
distance(0),
last_distance(-1)
{  
	saved_time = millis();
	refresh_time = 1000;
	blocked = false;

	pinMode(trig_pin, OUTPUT);
  	pinMode(echo_pin, INPUT);  
	
}

void Czujnik_odleglosci::print_data(LiquidCrystal* lcd, bool screen_change)
{

	if(distance != last_distance || screen_change)
	{
		lcd->clear();
		lcd->print("Dist: ");
		lcd->print(distance);
		last_distance = distance;
	}

	return;
}

void Czujnik_odleglosci::execute_task()
{
	unsigned long actual_time = millis();
  
	if(actual_time - saved_time >= refresh_time)
	{		
		digitalWrite(trig_pin, LOW);
	    delayMicroseconds(2);
	    digitalWrite(trig_pin, HIGH);
	    delayMicroseconds(10);
	    digitalWrite(trig_pin, LOW);

	    long time = pulseIn(echo_pin, HIGH);
	    distance = time / 58;

	    saved_time = millis();
	}
	return;
}

void Czujnik_odleglosci::write_info(char* buffer, int* i)
{
	copy_str("CZO\n", 4, buffer, *i);
	*i += 4;
}

int Czujnik_odleglosci::write_data(char* buffer)
{
	execute_task();
	int size = int_to_char(buffer, distance, 0);
	buffer[size] = '\n';

	return size + 1;

}
