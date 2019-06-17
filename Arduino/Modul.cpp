
#include "Modul.h"

int Modul::procces_data(char* send_buffer, char* recv_buffer, int pos)
{
	copy_str("ERR\n", 4, send_buffer, 0);

	return 4;
}

bool Modul::compare_str(char * com1, char * com2, int start, int size)
{
	int end = start + size;
	for(int i = 0; i < size; i++)
	{
		if(com1[i] != com2[i + start]) 
		{
			return false;
		}
	}

	return true;
}

int Modul::int_to_char(char * buffer, int x, int poz)
{
	if(x == 0)
	{
		buffer[0] = '0';
		return 1;
	}
	int pom = 10000;
	while(x / pom == 0)
	{
		pom /= 10;
	}
	//int poz = 0;
	while(pom != 0)
	{
		buffer[poz++] = char(int('0') + (x/pom));
		x %= pom;
		pom /= 10;
	}
	return poz;
}

void Modul::copy_str(char* str, int size, char* buff, int pos)
{
	for(int i = 0; i < size; i++)
	{
		buff[i + pos] = str[i];
	}
}

int Modul::char_to_int(char* buff, int* pos, char end)
{
	int  v = 0;
	while(buff[*pos] != end)
	{
		v *= 10;
		v += int(buff[*pos]) - int('0');
		(*pos)++; 
	}

	(*pos)++;

	return v;
}

