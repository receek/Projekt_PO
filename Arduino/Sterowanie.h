#ifndef Sterowanie_h
#define Sterowanie_h

#include "Arduino.h"
#include <LiquidCrystal.h>
#include <SPI.h>
#include <Ethernet.h>

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

	LiquidCrystal* lcd;

	EthernetServer* socket;
	EthernetClient client;

	Przycisk* up_button;
	Przycisk* down_button;
	Przycisk* apply_button;
	Przycisk* choose_button;
	
	int * tasks;
	Modul ** modules;


	bool compare_str(char*, char*, int);

	void read_request();
	int write_availble(char*);
	int write_modules_info(char *);
	int int_to_char(char*, int);
	void copy_str(char*, int, char*, int);



public:

 	Sterowanie(int, LiquidCrystal*, EthernetServer*, Przycisk*, Przycisk*, Przycisk*, Przycisk*);
 	~Sterowanie();

 	void working_loop();

 	void add_module(Modul*, int);

 	void begin();

};


#endif
