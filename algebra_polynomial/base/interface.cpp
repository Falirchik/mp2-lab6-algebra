#include "interface.h"

void Interface::Menu(){
	cout << "�������� ������������ �������: ";
	//������� ������ �������

	int point = -1;
	do {
		Print_Menu();
		cin >> point;
		switch (point) {
		case 1:
		//������� ���������� ��������
			Add_Pol(); break;
		case 2:
		//������� �������� ��������	
			Del_Pol(); break;
		case 3:
		//������� ������ ������ ���� ���������
			Print_All_Pol(); break;
		case 4:
		//������� ���������� ��������� �� ���������
			Calculation_Pol(); break;
		}
	} while (point != 5); //����� ��� ������� 5

}

void Interface::Print_Table(){
	cout << "1.�������� �� ������� \n 2.�������� �� ������\n 3.������������� �� �������\n 4.������\n 5.���-������� �� ������\n 6.���-������� �� �������"<<endl;
}

void Interface::Print_Menu(){
	cout << "\t\t ����\n";
	cout << "����� ������� �����, ������� ��������������� �����\n";
	cout << "1. �������� ����� �������\n";
	cout << "2. ������� ������������ �������\n";
	cout << "3. ������� ������ ���������\n";
	cout << "4. ��������� ���������\n";
	cout << "5. �����\n";
}

void Interface::Print_Operation(){
	cout << "1. ��������� �������\n";
	cout << "2. ������� ������������ �������\n";
	cout << "3. �����\n";
}

void Interface::Exit(){

}

void Interface::Add_Pol(){

}

void Interface::Del_Pol(){

}

void Interface::Print_All_Pol(){

}

void Interface::Calculation_Pol(){

}
