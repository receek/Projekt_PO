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
    bool remote;
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
    virtual bool is_tasking();

    virtual void print_data(LiquidCrystal*, bool);

    virtual void execute_task();

    virtual void write_info(char*, int*);
    virtual int write_data(char* buffer);
    virtual int procces_data(char*, char*, int);
};


#endif
