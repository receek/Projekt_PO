#ifndef Lampka_h
#define Lampka_h

#include "Arduino.h"

#include "Modul.h"

class Lampka : public Modul
{
private:
    int pin_analog_in;
    int pin_pwm;
    int value;
    int last_value;
    bool active;

public:

    Lampka() {}
    Lampka(int, int);

    // virtual void up_state(bool);
    // virtual void down_state(bool);
    virtual void apply_state(bool); 
    // virtual void choose_state(bool);

    virtual bool is_modyfing();
    virtual bool is_tasking();

    virtual void print_data(LiquidCrystal*, bool);

    virtual void execute_task();


  //virtual void define_module();
  //virtual void send_info();
  //virtual void receive_command();
};


#endif
