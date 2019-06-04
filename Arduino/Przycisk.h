#ifndef Przycisk_h
#define Przycisk_h

#include "Arduino.h"

class Przycisk
{
private:
	static const int first_push_time = 50; //ms
	static const int pushing_time = 20; //ms
	const int pin;
	bool state;
	
public:

	Przycisk(int in);

	bool get_state();
};


#endif