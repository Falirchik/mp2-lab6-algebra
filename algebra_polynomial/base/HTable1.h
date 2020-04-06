#pragma once
#include<iostream>
#include<math.h>

#define MAX_SIZE 10000

using namespace std;

template <class T>
struct TLine
{
	string key;
	T value;
	TLine<T>* pnext;
	int number_of_line;
};

template <class T>
class THashTable
{
private:

	TLine<T> line[MAX_SIZE];
	int count;

	int hash(string _key)
	{
		return ((int)(_key[0]) - 48);			// ����������� ������ ����� ����� � �����, ��������, ��� ����� ���������� � 48
	}

public:
	THashTable()
	{
		count = 0;
	}

	bool is_empty()												//�������� �� �������
	{
		if (count == 0)
			return true;
		else
			return false;
	}

	bool is_full()												//�������� �� �������
	{
		if (count == MAX_SIZE)
			return true;
		else
			return false;
	}

	void insert_line(string _key, T _value)				//�������
	{
		if (is_full == true)
			throw "Table is full!";
		int hashkey = hash(_key);

		if (line[hashkey].number_of_line == 0)		//���� ������
		{
			line[hashkey].value = _value;
			line[hashkey].key = _key;
		}
		else								//���� ��� �������� ���-��, �� ������� ��������� �����
		{
			line[hashkey].pnext = new TLine<T>;
			TLine<T>* p = new TLine<T>;
			p = line[hashkey].pnext;
			for (int i = 0; i < line[hashkey].number_of_line - 1; i++)			//��������� �� ���� �����, ���� �� ������ �� �����
			{
				p->pnext = new TLine<T>;
				p = p->pnext;
			}
			p->value = _value;
			p->nameOfLine = _key;
		}
		line[hashkey].number_of_line++;		//������ ��� ��������� ����� �����
		count++;					//����������� ����� ����� � ���-�������
	}

	int search_in_table_by_name(string _key)						//�����
	{
		int hashkey = hash(_key);				// �����, ��� ����� �������
		if (is_empty() == true)
			return -1;
		if (line[hashkey].key == _key)			// ���� ����� ������
		{
			return 1;
		}
		else									//����� ��������� � ���������� ����� � ���� ���� ���
		{
			TLine<T>* p = new TLine<T>;
			p = line[hashkey].pnext;
			for (int i = 0; i < line[hashkey].number_of_line - 1; i++)
			{
				if (p->key == _key)
					return 1;
				p = p->pnext;
			}
		}
		return -1;
	}

	void delete_line(string _key)						//��������
	{
		int a;
		if (is_empty == true)							//�������� �� �������
			throw "Table is empty!";

		if (search_in_table_by_name(_key) == -1)		//�������� �� �������������
			throw "Is not exist!";
		int hashkey = hash(_key);				//��������� ���-�����(������� � ���-������)

		if (line[hashkey].number_of_line == 1)		//���� ���� �����
		{
			T _value;
			line[hashKey].key = "";
			line[hashKey].value = _value;

		}
		else										//���� ������ ������
		{
			TLine<T>* p = new TLine<T>;
			p = line[hashkey].pnext;				//��������� � ����
			while (p->key != _key)						//���� �� ������ ����
			{
				p->pnext;								//��������� � ����������
				a++;									//����������, ������� ������
			}
			TLine<T>* pp = new TLine<T>;
			pp = line[hashkey].pnext;
			for (int i = 0; i < count - 2; i++)
			{
				pp = pp->pnext;
			}
			pp->pnext = p->pnext;
			delete p;
		}
		line[hashkey].number_of_line--;
		count--;
	}
};