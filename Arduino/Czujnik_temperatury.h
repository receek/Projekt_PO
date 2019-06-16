#ifndef Czujnik_temperatury_h
#define Czujnik_temperatury_h

#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#include "Modul.h"

class Czujnik_temperatury : public Modul
{
private:
	int pin;
	float temperature, last_temp;
	OneWire wire;
	DallasTemperature sensor;
	DeviceAddress address;
  
public:

	Czujnik_temperatury(): wire(0) {}
 	Czujnik_temperatury(int, uint8_t[]);

	virtual void print_data(LiquidCrystal*, bool);

	virtual void execute_task();

	virtual void write_info(char*, int*);
	virtual int write_data(char*);
};


#endif
