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
	char Exit();					//подтвердить выход
	void Add_Pol();					//добавление полинома
	void Del_Pol();					//удаление полинома
	void Print_All_Pol();			//вывод всех полиномов
	void Calculation_Pol();			//вычисление полинома

};