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
