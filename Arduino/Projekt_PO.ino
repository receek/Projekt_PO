
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//#include "DHT.h"

#include "Czujnik_temperatury.h"


uint8_t address[] = {0x28, 0x36, 0x18, 0x01, 0x00, 0x00, 0x80, 0x00};

LiquidCrystal lcd(27, 29, 31, 33, 35, 37);
Czujnik_temperatury czujnik(36, address);

void setup() {
  // put your setup code here, to run once:

  lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:

  czujnik.execute_task();
  czujnik.print_data(&lcd);

}
