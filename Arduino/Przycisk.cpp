#include "Przycisk.h"

Przycisk::Przycisk(int in) : pin(in), state(false)
{
	pinMode(in, INPUT);
}

bool Przycisk::get_state()
{
	if(digitalRead(pin) == HIGH)
	{
		if(state) //przycisk jest wciśnięty od jakiegoś czasu
		{
			delay(pushing_time);

			if(digitalRead(pin) == LOW) // przycisk został zwolniony
				state = false;
		}
		else //przycisk został dopiero co naciśniety lub złapaliśym zakłócenie
		{
			delay(first_push_time);

			if(digitalRead(pin) == HIGH) // to nie było zakłócenie
				state = true; 
		}
	}
	else if(digitalRead(pin) == LOW)
	{
		if(state)
			state = false;
	}

	return state;
}
