
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

bool Czujnik_odleglosci::is_modyfing()
{
	return false;
}*/

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
