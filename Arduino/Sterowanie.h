#ifndef Sterowanie_h
#define Sterowanie_h

#include "Arduino.h"
#include <LiquidCrystal.h>

#include "Przycisk.h"
#include "Modul.h"

class Sterowanie
{
private:

	int modules_number;
	int module_index;
	int tasks_number;
	int remote_module;
	bool modyfing;
	bool screen_change;

	int * tasks;

	LiquidCrystal* lcd;

	Przycisk* up_button;
	Przycisk* down_button;
	Przycisk* apply_button;
	Przycisk* choose_button;

	Modul ** modules;

public:

 	Sterowanie(int, LiquidCrystal*, Przycisk*, Przycisk*, Przycisk*, Przycisk*);

 	void working_loop();

 	void add_module(Modul*, int);

 	void begin();

};


#endif
