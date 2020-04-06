#include "interface.h"

void Interface::Menu(){
	cout << "Выберите используемую таблицу: ";
	//функция выбора таблицы

	int point = -1;
	do {
		Print_Menu();
		cin >> point;
		switch (point) {
		case 1:
		//функция добавления полинома
			Add_Pol(); break;
		case 2:
		//функция удаления полинома	
			Del_Pol(); break;
		case 3:
		//функция вывода списка всех полиномов
			Print_All_Pol(); break;
		case 4:
		//функция вычисления выражения из полиномов
			Calculation_Pol(); break;
		}
	} while (point != 5); //выход при нажатии 5

}

void Interface::Print_Table(){
	cout << "1.Линейная на массиве \n 2.Линейная на списке\n 3.Упорядоченная на массиве\n 4.Дерево\n 5.Хэш-таблица на списке\n 6.Хэш-таблица на массиве"<<endl;
}

void Interface::Print_Menu(){
	cout << "\t\t МЕНЮ\n";
	cout << "Чтобы выбрать пункт, введите соответствующую цифру\n";
	cout << "1. Добавить новый полином\n";
	cout << "2. Удалить существующий полином\n";
	cout << "3. Вывести список полиномов\n";
	cout << "4. Вычислить выражение\n";
	cout << "5. Выход\n";
}

void Interface::Print_Operation(){
	cout << "1. Посчитать полином\n";
	cout << "2. Удалить существующий полином\n";
	cout << "3. Выход\n";
}

char Interface::Exit(){
	char a;
	cout << "Выйти? (Y/N)" << endl;
	cin >> a;
	return a;
}

void Interface::Add_Pol(){

}

void Interface::Del_Pol(){

}

void Interface::Print_All_Pol(){

}

void Interface::Calculation_Pol(){

}
