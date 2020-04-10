#pragma once
#include<iostream>
#include<math.h>

#define MAX_SIZE 10000

using namespace std;
/*
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

	THashLine<T> line[MAX_SIZE];
	int count;

	int hash(string _key)
	{
		return ((int)(_key[0]) - 48);			// преобразуем первую букву ключа в число, учитывая, что буквы начинаются с 48
	}

public:
	THashTable()
	{
		count = 0;
	}

	bool is_empty()												//проверка на пустоту
	{
		if (count == 0)
			return true;
		else
			return false;
	}

	bool is_full()												//проверка на полноту
	{
		if (count == MAX_SIZE)
			return true;
		else
			return false;
	}

	void insert_line(string _key, T _value)
	{
		if (is_full == true)
			throw "Table is full!";
		int hashkey = hash(_key);

		if (line[hashkey].number_of_line == 0)		//если первое
		{
			line[hashkey].value = _value;
			line[hashkey].key = _key;
		}
		else								//если уже записано что-то, то создаем следующее звено
		{
			line[hashkey].pnext = new TLine<T>;
			TLine<T>* p = new TLine<T>;
			p = line[hashkey].pnext;
			for (int i = 0; i < line[hashkey].number_of_line - 1; i++)			//переходим на след звено, пока не дойдем до конца
			{
				p->pnext = new TLine<T>;
				p = p->pnext;
			}
			p->value = _value;
			p->nameOfLine = _key;
		}
		line[hashkey].number_of_line++;		//каждый раз фиксируем новое звено
		count++;					//увеличиваем число строк в хеш-таблице
	}

	int search_in_table_by_name(string _key)						//поиск
	{
		int hashkey = hash(_key);				// место, где лежит элемент
		if (is_empty() == true)
			return -1;
		if (line[hashkey].key == _key)			// ключ сразу совпал
		{
			return 1;
		}
		else									//иначе переходим к следующему звену и ищем ключ там
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

	void delete_line(string _key)
	{
		int a;
		if (is_empty == true)
			throw "Table is empty!";

		if (search_in_table_by_name(_key) == -1)
			throw "Is not exist!";
		int hashkey = hash(_key);

		if (line[hashkey].number_of_line == 1)
		{
			T _value;
			line[hashKey].key = "";
			line[hashKey].value = _value;

		}
		else
		{
			TLine<T>* p = new TLine<T>;
			p = line[hashkey].pnext;				//переходим к след
			while (p->key != _key)						//пока не найдем ключ
			{
				p->pnext;								//переходим к следующему
				a++;									//запоминаем, сколько прошли
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
*/
