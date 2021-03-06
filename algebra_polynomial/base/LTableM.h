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
class TOrderedTable
{
private:
	TLine<T>* line;
	unsigned int count;						// ����� �����
	unsigned int number_of_line;

public:

	TLineTables()
	{
		line = nullptr;
		count = 0;
		number_of_line = 0;
	}

	TLineTables(int _number_of_line)
	{
		if (_number_of_line < 0 || _number_of_line > MAX_SIZE)
			throw "Number of line is not correct!";
		number_of_line = _number_of_line;
		line = new TLine<T>[_number_of_line];
		count = 0;
	}

	~TLineTables() {}

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
		if (is_full() == true)
			throw "The table is full!";

		int position = 0;
		TLine<T> temp;
		while (_value <= line[position].value)
			position++;
		temp = line[position];
		line[position].key = _key;
		line[position].pValue = _value;
		count++;
		int flag = 1;
		TLine<T> tmp;
		for (int i = position + 1; i < count; i++)
		{
			if (flag)
			{
				tmp = line[i];
				line[i] = temp;
				flag--;
			}
			else
			{
				temp = line[i];
				line[i] = tmp;
				flag++;
			}
		}
	}

	void Delete_Line(string _key)
	{
		if (Is_Empty() == true)
			throw "The table is empty!";
		int position = Search_In_Table_By_Name(_key);
		if (position == -1)
			throw "This line does not exist!";
		for (int i = 0; i < count - 1; i++)
		{
			line[i].key = line[i + 1].key;
			line[i].value = line[i + 1].value;
		}
		line[count].key = '\0';
		count--;
	}

	void Print_Table()
	{
		cout << "Table" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << "����" <<        << "��������" << endl;
			cout << line[i].key<<      << line[i].value << endl;
		}
	}
};