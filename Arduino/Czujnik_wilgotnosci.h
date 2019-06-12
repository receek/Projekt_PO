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

	//Czujnik_wilgotnosci() {}
 	Czujnik_wilgotnosci(int);

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
