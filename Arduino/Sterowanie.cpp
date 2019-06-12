
#include "Sterowanie.h"

Sterowanie::Sterowanie(int mod_num, LiquidCrystal* screen, Przycisk* up, Przycisk* down, Przycisk* apply, Przycisk* choose) :
modules_number(mod_num), 
module_index(0),
remote_module(-1),
tasks_number(0),
modyfing(false),
screen_change(true),
lcd(screen), 
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


void Sterowanie::working_loop()
{
	//lcd->clear();
	//lcd->print("start");

	if(modyfing)
	{
		//lcd->clear();
		//lcd->print("mod");	
		modules[module_index]->up_state(up_button->get_state());
		modules[module_index]->down_state(down_button->get_state());

		if(remote_module != module_index && choose_button->get_state())
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
		//lcd->clear();
		//lcd->print("not mod1");
		if(up_button->get_state() && module_index < modules_number - 1)
		{
		//	lcd->clear();
		//lcd->print("not mod12");
			delay(200);
			screen_change = true;
			module_index++;
		}

		//lcd->clear();
		//lcd->print("not mod2");
		
		if(down_button->get_state() && module_index > 0)
		{
			//lcd->clear();
			//lcd->print("not mod2");
			delay(200);
			screen_change = true;
			module_index--;
		}

		//lcd->clear();
		//lcd->print("not mod3");

		modules[module_index]->apply_state(apply_button->get_state());

		//lcd->clear();
		//lcd->print("not mod4");

		if(choose_button->get_state())
		{
			//lcd->clear();
			//lcd->print("not mod4in");
			modules[module_index]->choose_state(true);
			screen_change = true;
			delay(500);

			if(modules[module_index]->is_modyfing())
			{
				lcd->clear();
				lcd->print("to mod");
				
				modyfing = true;
			}
		}

	//	lcd->clear();
	//	lcd->print("not mod5");
	}

	// Obsługa ethernet //

	//lcd->clear();
	//lcd->print("before print");
	modules[module_index]->print_data(lcd, screen_change);

	// Zadania w tle //
	//lcd->clear();
	//lcd->print("before task");
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