#ifndef Czujnik_wilgotnosci_h
#define Czujnik_wilgotnosci_h

#include "Arduino.h"
#include "DHT.h"

#include "Modul.h"

class Czujnik_wilgotnosci : public Modul
{
private:
	int pin;
	int humidity;
	int last_humidity;

	DHT sensor;

  
public:

 	Czujnik_wilgotnosci(int);

	virtual void print_data(LiquidCrystal*, bool);

	virtual void execute_task();

	virtual void write_info(char*, int*);
	virtual int write_data(char*);
};


#endif
