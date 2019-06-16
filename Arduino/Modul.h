#ifndef Modul_h
#define Modul_h

#include "Arduino.h"

#include <LiquidCrystal.h>
#include <SPI.h>
#include <Ethernet.h>

class Modul
{
private:
  
  
protected:
	unsigned long saved_time;
	unsigned long refresh_time;

	bool blocked;
	Modul() {}
	
  	bool compare_str(char*, char*, int, int);

public:

	virtual void up_state(bool) {}
	virtual void down_state(bool) {}
	virtual void apply_state(bool) {} 
	virtual void choose_state(bool) {}

	virtual bool is_modyfing() { return false; }
	virtual bool is_tasking() { return false; }

	virtual void print_data(LiquidCrystal*, bool) {}

	virtual void execute_task() {}

	virtual void write_info(char*, int*);
	virtual int write_data(char*) {} //; do zmiany
	virtual int procces_data(char*, char*, int);

	virtual int int_to_char(char*, int, int);
	virtual void copy_str(char*, int, char*, int);
};


#endif
