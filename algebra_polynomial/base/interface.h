#pragma once

#include <iostream>

using namespace std;
//����������� ������
//����������� ����������� �������, ���� �����

class Interface {

public:
	Interface() {

	}
	void Menu();					//����� ����
	void Print_Table();				//�������� ����� ��������� �������
	void Print_Menu();				//������ ���� �� �����
	void Print_Operation();			//������ ������ �������� 
	void Exit();
	void Add_Pol();
	void Del_Pol();
	void Print_All_Pol();
	void Calculation_Pol();

};

