#ifndef Przycisk_h
#define Przycisk_h

#include "Arduino.h"

class Przycisk
{
private:
	static const int first_push_time = 30; //ms
	static const int pushing_time = 200; //ms
	const int pin;
	bool state;
	
public:

	Przycisk(int in);

	bool get_state();
};


#endif