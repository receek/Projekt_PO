
#include "Sterowanie.h"

Sterowanie::Sterowanie(int mod_num, LiquidCrystal* screen, EthernetServer * sockt, Przycisk* up, Przycisk* down, Przycisk* apply, Przycisk* choose) :
modules_number(mod_num), 
module_index(0),
remote_module(-1),
tasks_number(0),
modyfing(false),
screen_change(true),
lcd(screen),
socket(sockt), 
up_button(up), 
down_button(down), 
apply_button(apply), 
choose_button(choose)
{
	modules = new Modul*[mod_num];
	tasks = new int[mod_num];

	for(int i = 0 ; i < mod_num; i++)
	{
		modules[i] = 0;
	}

}

Sterowanie::~Sterowanie()
{
	for(int i = 0 ; i < modules_number; i++)
	{
		if(modules[i] != 0) 
		{
			delete modules[i];
		}
	}

	delete tasks;
}


void Sterowanie::working_loop()
{
	if(modyfing)
	{	
		modules[module_index]->up_state(up_button->get_state());
		modules[module_index]->down_state(down_button->get_state());

		if(choose_button->get_state())
		{
			
			modules[module_index]->choose_state(true);
			screen_change = true;
			delay(500);

			if(!(modules[module_index]->is_modyfing()))
			{
				modyfing = false;
			}	
		}
	}
	else
	{
		if(up_button->get_state() && module_index < modules_number - 1)
		{
			delay(400);
			screen_change = true;
			module_index++;
		}
		
		if(down_button->get_state() && module_index > 0)
		{
			delay(400);
			screen_change = true;
			module_index--;
		}

		modules[module_index]->apply_state(apply_button->get_state());

		if(choose_button->get_state())
		{
			modules[module_index]->choose_state(true);
			screen_change = true;
			delay(500);

			if(modules[module_index]->is_modyfing())
			{
				modyfing = true;
			}
		}
	}

	client = socket->available();
	if(client)
	{
		read_request();
	}

	modules[module_index]->print_data(lcd, screen_change);

	modules[module_index]->execute_task();

	for(int i = 0; i < tasks_number; i++)
	{
		if(tasks[i] == i) continue;

		modules[tasks[i]]->execute_task();
	}

	screen_change = false;

}

void Sterowanie::add_module(Modul* m, int index)
{
	if(index < 0 || index >= modules_number)
	{
		lcd->clear();
		lcd->print("Moduling error");
		lcd->setCursor(0, 1);
		lcd->print("Index out");
		while(true) 
		{
			delay(10000);
		}
	}

	modules[index] = m;

	return;
}


void Sterowanie::begin()
{
	for(int i = 0; i < modules_number; i++)
	{
		if(modules[i] == 0)
		{
			lcd->clear();
			lcd->print("Begin error");
			lcd->setCursor(0, 1);
			lcd->print("No init module");
			while(true) 
			{
				delay(10000);
			}
		}

		if(modules[i]->is_tasking())
		{
			tasks[tasks_number] = i;
			tasks_number++;
		}
	}
}

bool Sterowanie::compare_str(char * com1, char * com2, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(com1[i] != com2[i]) 
		{
			return false;
		}
	}

	return true;
}

void Sterowanie::read_request()
{
	char recv_buffer[100];
	char send_buffer[100];

	int i = 0;
	int size = 0;

	recv_buffer[i] = client.read();

	while(recv_buffer[i] != '\n' && client.available())
	{
		i++;
		recv_buffer[i] = client.read();
	}

	if(compare_str("HLL", recv_buffer, 3))
	{
		size = write_availble(send_buffer);
	}
	else if(compare_str("ASK", recv_buffer, 3))
	{
		size = write_modules_info(send_buffer);
	}
	else if (compare_str("VAL", recv_buffer, 3))
	{
		i = 4;
		int  v = 0;
		while(recv_buffer[i] != '\n')
		{
			v *= 10;
			v += int(recv_buffer[i]) - int('0');
			i++; 
		}

		if(modules[v]->is_modyfing())
		{
			copy_str("BLC\n", 4, send_buffer, 0);
			size = 4;
		}
		else
		{
			size = modules[v]->write_data(send_buffer);
		}

	}
	else if (compare_str("COM", recv_buffer, 3))
	{
		i = 4;
		int  v = 0;
		while(recv_buffer[i] != ' ' && recv_buffer[i] != '\n')
		{
			v *= 10;
			v += int(recv_buffer[i]) - int('0');
			i++; 
		}
		i++;
		
		if(modules[v]->is_modyfing())
		{
			copy_str("BLC\n", 4, send_buffer, 0);
			size = 4;
		}
		else
		{
			size = modules[v]->procces_data(send_buffer, recv_buffer, i);
		}	
	}

	client.write(send_buffer, size);

	delay(5);
	client.stop();


}

int Sterowanie::write_availble(char * buffer)
{
	copy_str("AVL\n", 4, buffer, 0);

	return 4;
}

int Sterowanie::write_modules_info(char * buffer)
{
	int i = int_to_char(buffer, modules_number);
	buffer[i++] = '\n';

	for(int j = 0; j < modules_number; j++)
	{
		modules[j]->write_info(buffer, &i);
	}

	return i;
}

int Sterowanie::int_to_char(char * buffer, int x)
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
	int poz = 0;
	while(pom != 0)
	{
		buffer[poz++] = char(int('0') + (x/pom));
		x %= pom;
		pom /= 10;
	}
	return poz;
}

void Sterowanie::copy_str(char* str, int size, char* buff, int pos)
{
	for(int i = 0; i < size; i++)
	{
		buff[i + pos] = str[i];
	}
}
