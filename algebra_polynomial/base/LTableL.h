#pragma once

#include <string>

#define MAX_SIZE 10000

using namespace std;

template <class T>
struct TLine
{
	string key;
	T value;
};
template <class T>
class TLineTable
{
private:
	TLine<T>* line;
	unsigned int count;						// ÷èñëî ñòğîê
	unsigned int number_of_line;

public:

	TLineTable()
	{
		line = nullptr;
		count = 0;
		number_of_line = 0;
	}

	TLineTable(int _number_of_line)
	{
		if (_number_of_line < 0 || _number_of_line > MAX_SIZE)
			throw "Number of line is not correct!";
		number_of_line = _number_of_line;
		line = new TLine<T>[_number_of_line];
		count = 0;
	}

	~TLineTable() {}

	bool Is_Empty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}

	bool Is_Full()
	{
		if (count == number_of_line)
			return true;
		else
			return false;
	}

	int Search_In_Table_By_Name(string _key)
	{
		if (Is_Empty() == true)
			return -1;
		for (int i = 0; i < count; i++)
		{
			if (line[i].key == _key)
				return i;
		}
		return -1;
	}

	void Insert_Line(string _key, T _value)
	{
		if (Is_Full() == true)
			throw "The table is full!";
		line[count].key = _key;
		line[count].value = _value;
		count++;
	}

	void Delete_Line(string _key)
	{
		if (Is_Empty() == true)
			throw "The table is empty!";
		int position = Search_In_Table_By_Name(_key);
		if (position == -1)
			throw "This line does not exist!";

		line[position].key = line[count - 1].key;
		line[position].value = line[count - 1].value;
		line[count].key = '\0';
		count--;
	}

	void Print_Table()
	{
		cout << "Table" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << "ÊËŞ×" <<        << "ÇÍÀ×ÅÍÈÅ" << endl;
			cout << line[i].key<<      << line[i].value << endl;
		}
	}
};