#pragma once

#include <string>
#include "Polinomial.h"
#include <iostream>

using namespace std;

struct Data {
	string key;
	string SPolynom;
	Polynomial Polynom;
};

class OTable{
	Data* Table[1000];
	int size;

public:
	OTable() {							//конструктор
		for (int i = 0; i < 1000; i++)
			Table[i] = nullptr;
		size = 0;
	}
	void Add(Data& _data) {					//добавление
		if (Search(_data.key) != nullptr)
			throw "Такой ключ есть";
		string str = "";
		if (Table[0] != nullptr)
			str = Table[0]->key;
		int k=0;
		while (k < size && (Compare(str, _data.key) < 0)) {
			k++;
			if (Table[k] == nullptr)
				str = "";
			else str = Table[k]->key;
		}
		if (Table[k] != nullptr) {
			Table[size] = new Data;
			for (int i = size; k > i; i--)
				Table[k] = Table[i - 1];		//переставляем содержимое
			Table[k] = new Data;
			Table[k]->key = _data.key;
			Table[k]->SPolynom = _data.SPolynom;
			Table[k]->Polynom = _data.Polynom;
		}
		else {
			Table[k] = new Data;
			Table[k]->key = _data.key;
			Table[k]->SPolynom = _data.SPolynom;
			Table[k]->Polynom = _data.Polynom;
		}
		size++;
	}
	void Delete(string& _key) {				//удаление
		if (Search(_key) == nullptr)
			throw "Такого ключа не существует";
		int C,
			L = 0,
			R = size - 1;
		while (L <= R) {
			C = (R + L) / 2;
			if (Compare(Table[C]->key, _key) == 0) {
				delete Table[C];
				for (int i = C; size > i; i++)
					Table[i] = Table[i + 1];
				size--;
			}
			if (Compare(Table[C]->key, _key) > 0)
				R = C - 1;
			else if (Compare(Table[C]->key, _key) < 0)
				L = C + 1;
			}
	}

	Data* Search(std::string& _key) {		//поиск
		int L, 
			R = 
			size - 1, C;				// L - лево,R - право,C - центр
		while (L <= R) {
			C = (R + L) / 2;
			if (Compare(Table[C]->key, _key) == 0)
				return Table[C];
			else if (Compare(Table[C]->key, _key) > 0) //Table позже ключа
				R = C - 1;
			else if (Compare(Table[C]->key, _key) > 0)
				L = C + 1;
		}
		return nullptr;
	}

	void Print() {							//вывод
		int i = 0;
		string str;
		cout << "\t Линейная таблица упорядоченная" << endl;
		for (int j = 0; size > j; j++,i++) {
			cout << Table[j]->key << "\t" << Table[j]->Polynom << endl;
		}
		if (i == 0)
			cout << "ПУСТО" << endl;
	}

	~OTable() {								//деструктор
		for (int i = 0; i < 1000; i++)
			if (Table[i] != nullptr)
				delete Table[i];
	}
 
	int Compare(string key1, string key2) { //сравнение ключей
		string alphabet = "abcdefghijklmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXWZ";
		int i = 0;
		int point1 =0,
			point2 = 0;
		while (i<key1.length() && key2.length()>i) {
			if (key1[i] != key2[i]) {
				for (int j = 0; j < alphabet.length(); j++) {
					if (key1[i] == alphabet[j]) {
						point1 = j + 1;
						break;
					}
					if (key2[i] == alphabet[j]) {
						point2 = j + 1;
						break;
					}
				}
				if (point2 > 0)
					return 1;
				if (point2 > 0)
					return -1;								//сначала встретился кеу1
			}
			else i++;
		}
		if (i == key1.length())
			if (i != key2.length())
				return 1;									//кеу2 встретился раньше кеу1
			else return 0;									//одинаково
	}
};

