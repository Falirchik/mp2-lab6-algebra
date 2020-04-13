#pragma once
#include <iostream>
#include <cmath>

#define MAX_SIZE 10000

using namespace std;

template <class T>
struct TLine
{
	string key;								//
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

	int In_Hash(string _key)
	{
		return ((int)(_key[0]) - 48);			// преобразуем первую букву ключа в число, учитывая, что буквы начинаются с 48
	}

public:
	THashTable()
	{
		count = 0;
	}

	bool Is_Empty()												//проверка на пустоту
	{
		if (count == 0)
			return true;
		else
			return false;
	}

	bool Is_Full()												//проверка на полноту
	{
		if (count == MAX_SIZE)
			return true;
		else
			return false;
	}

	void Insert_Line(string _key, T _value)				//вставка
	{
		if (Is_Full == true)
			throw "Table is full!";
		int hashkey = In_Hash(_key);

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

	int Search_In_Table_By_Name(string _key)						//поиск
	{
		int hashkey = In_Hash(_key);				// место, где лежит элемент
		if (Is_Empty() == true)
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

	void delete_line(string _key)						//удаление
	{
		int a;
		if (Is_Empty == true)							//проверка на пустоту
			throw "Table is empty!";

		if (Search_In_Table_By_Name(_key) == -1)		//проверка на существование
			throw "Is not exist!";
		int hashkey = In_Hash(_key);				//получение кеш-ключа(индекса в хеш-таблце)

		if (line[hashkey].number_of_line == 1)		//если одно звено
		{
			T _value;
			line[hashKey].key = "";
			line[hashKey].value = _value;

		}
		else										//если больше одного
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

	void Print_Table()
	{
		for (int i = 0; i <; i++)
		{

		}

		for (int i = 0; i < line[].number_of_line - 1; i++)
		{

		}
	}
};
