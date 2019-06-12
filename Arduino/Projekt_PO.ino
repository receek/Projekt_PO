
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include "Sterowanie.h"
#include "Czujnik_temperatury.h"
#include "Czujnik_odleglosci.h"
#include "Czujnik_wilgotnosci.h"
#include "Buzzer.h"
#include "RGB_led.h"
#include "Lampka.h"


const Przycisk up(46);
const Przycisk down(47);
const Przycisk apply(48);
const Przycisk choose(49);

uint8_t address[] = {0x28, 0x36, 0x18, 0x01, 0x00, 0x00, 0x80, 0x00};
int PWM[] = {2, 3, 4}; 

LiquidCrystal lcd(22, 23, 24, 25, 26, 27);
Czujnik_temperatury czujnik_temp(36, address);
Buzzer glosnik(5);
RGB_led dioda(PWM);
Czujnik_odleglosci czujnik_odl(30, 31);
Czujnik_wilgotnosci czujnik_wilg(37);
Lampka lampka(A1, 6);




Sterowanie sterownik(6, &lcd, &up, &down, &apply, &choose);

void setup() 
{
  // put your setup code here, to run once:

	lcd.begin(16, 2);

	sterownik.add_module(&czujnik_odl, 0);
	sterownik.add_module(&dioda, 1);
	sterownik.add_module(&czujnik_temp, 2);
	sterownik.add_module(&glosnik, 3);
	sterownik.add_module(&czujnik_wilg, 4);
	sterownik.add_module(&lampka, 5);

	sterownik.begin();

}

void loop() 
{
  // put your main code here, to run repeatedly:

	sterownik.working_loop();
}
