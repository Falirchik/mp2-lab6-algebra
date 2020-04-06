#pragma once

#include <iostream>

using namespace std;
//подключение таблиц
//подключение необходимых классов, если нужно

class Interface {

public:
	Interface() {

	}
	void Menu();					//вызов меню
	void Print_Table();				//печатает выбор доступные таблицы
	void Print_Menu();				//печать меню на экран
	void Print_Operation();			//печать выбора операций 
	void Exit();
	void Add_Pol();
	void Del_Pol();
	void Print_All_Pol();
	void Calculation_Pol();

};

