#ifndef Czujnik_odleglosci_h
#define Czujnik_odleglosci_h

#include "Arduino.h"

#include "Modul.h"

class Czujnik_odleglosci : public Modul
{
private:
	int echo_pin;
	int trig_pin;
	long distance;
	long last_distance;

  
public:

	Czujnik_odleglosci() {};
 	Czujnik_odleglosci(int, int);

	virtual void print_data(LiquidCrystal*, bool);

	virtual void execute_task();

	virtual void write_info(char*, int*);
	virtual int write_data(char*);
};


#endif
