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

	//virtual void up_button(bool);
    //virtual void down_button(bool);
    //virtual void apply_button(bool); 
    //virtual void choose_button(bool);

   //virtual bool is_modyfing();

	virtual void print_data(LiquidCrystal*, bool);

	virtual void execute_task();


  //virtual void define_module();
  //virtual void send_info();
  //virtual void receive_command();
};


#endif
