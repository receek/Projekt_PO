#include "Sterowanie.h"
#include "Czujnik_temperatury.h"
#include "Czujnik_odleglosci.h"
#include "Czujnik_wilgotnosci.h"
#include "Buzzer.h"
#include "RGB_led.h"
#include "Lampka.h"


LiquidCrystal lcd(22, 23, 24, 25, 26, 27);

// niby każde urządzenie w sieci musi mieć unikalny adres mac ale kto to będzie sprawdzał...
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);
EthernetServer server(8888);

Przycisk up(46);
Przycisk down(47);
Przycisk apply(48);
Przycisk choose(49);

Sterowanie sterownik(6, &lcd, &server, &up, &down, &apply, &choose);

void setup() 
{
	Serial.begin(9600);
  // put your setup code here, to run once
	uint8_t address[] = {0x28, 0x36, 0x18, 0x01, 0x00, 0x00, 0x80, 0x00};
	int PWM[] = {2, 3, 4}; 
	
	sterownik.add_module(new Czujnik_odleglosci(30, 31), 0);
	sterownik.add_module(new RGB_led(PWM), 1);
	sterownik.add_module(new Czujnik_temperatury(36, address), 2);
	sterownik.add_module(new Buzzer(5), 3);
	sterownik.add_module(new Czujnik_wilgotnosci(37), 4);
	sterownik.add_module(new Lampka(A1, 6), 5);

	lcd.begin(16, 2);
	Ethernet.begin(mac, ip);

	sterownik.begin();

}

void loop() 
{
  // put your main code here, to run repeatedly:

	sterownik.working_loop();
}
