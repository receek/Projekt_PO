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

  //Modul();
  
public:

  //virtual int get_id();

  virtual void up_pushed();
  virtual void down_pushed();
  virtual void apply_pushed();
  virtual void choose_pushed();

  virtual void print_data(LiquidCrystal*);

  //metoda do sprawdzenia czasu
  virtual void execute_task();

  //virtual void define_module();
  //virtual void send_info();
  //virtual void receive_command();
};


#endif
