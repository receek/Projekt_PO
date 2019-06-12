#ifndef Modul_h
#define Modul_h

#include "Arduino.h"

#include <LiquidCrystal.h>

class Modul
{
private:
  
  
protected:
	unsigned long saved_time;
	unsigned long refresh_time;

	bool blocked;
	//bool remote_blocked;
	Modul() {}
	
  
public:
	
  //virtual int get_id();

	virtual void up_state(bool) {}
	virtual void down_state(bool) {}
	virtual void apply_state(bool) {} 
	virtual void choose_state(bool) {}

	virtual bool is_modyfing() { return false; }
	virtual bool is_tasking() { return false; }

	virtual void print_data(LiquidCrystal*, bool) {}

  //metoda do sprawdzenia czasu
	virtual void execute_task() {}


  //virtual void define_module();
  //virtual void send_info();
  //virtual void receive_command();
};


#endif
