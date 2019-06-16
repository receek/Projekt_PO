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
    int range;
    bool active;

public:

    Lampka() {}
    Lampka(int, int);

    virtual void apply_state(bool); 

    virtual bool is_modyfing();
    virtual bool is_tasking();

    virtual void print_data(LiquidCrystal*, bool);

    virtual void execute_task();

    virtual void write_info(char*, int*);
    virtual int write_data(char* buffer);
    virtual int procces_data(char*, char*, int);
};


#endif
