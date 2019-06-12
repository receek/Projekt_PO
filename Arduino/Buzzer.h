#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

#include "Modul.h"

class Buzzer : public Modul
{
private:
    int pin;
    int value;
    int last_value;
    bool pushed;
    bool buzzing;
    bool modyfing;
  
public:

    Buzzer() {}
    Buzzer(int);

    virtual void up_state(bool);
    virtual void down_state(bool);
    virtual void apply_state(bool); 
    virtual void choose_state(bool);

    virtual bool is_modyfing();

    virtual void print_data(LiquidCrystal*, bool);

    virtual void execute_task();


  //virtual void define_module();
  //virtual void send_info();
  //virtual void receive_command();
};


#endif
