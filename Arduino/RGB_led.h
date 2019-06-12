#ifndef RGB_led_h
#define RGB_led_h

#include "Arduino.h"

#include "Modul.h"

class RGB_led : public Modul
{
private:
    int pins[3];
    int value[3];
    int last_value[3];
    int modyfing;

    bool active;
  
public:

    RGB_led() {}
    RGB_led(int[]);

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