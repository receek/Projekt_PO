#ifndef Sterowanie_h
#define Sterowanie_h

#include "Arduino.h"
#include <LiquidCrystal.h>

#include "Przycisk.h"

class Sterowanie
{
private:

  unsigned long timer;

  LiquidCrystal* lcd;

  Przycisk* increase_button;
  Przycisk* decrease_button;
  Przycisk* apply_button;
  Przycisk* choose_button;

  //ETH i Module pointer

  bool increase_pushed();
  bool decrease_pushed();
  bool apply_pushed();
  bool choose_pushed();  

public:

  Sterowanie(LiquidCrystal*, Przycisk*, Przycisk*, Przycisk*, Przycisk*);


};


#endif
