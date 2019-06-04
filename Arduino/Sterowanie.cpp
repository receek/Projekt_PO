
#include "Sterowanie.h"

Sterowanie::Sterowanie(LiquidCrystal* screen, Przycisk* up, Przycisk* down, Przycisk* apply, Przycisk* choose)
: timer(millis()), increase_button(up), decrease_button(down), apply_button(apply), choose_button(choose)
{
  
  
}
