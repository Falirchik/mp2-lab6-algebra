#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include <iostream>
#include <sstream>
#include "stack.h"
#include "HTable1.h"
#include "Polynomial.h"

#define MaxSizeString 100

using namespace std;

struct TablFunc     //таблица операций
{
	char func[7];
	int priority[7];
	int count;
	TablFunc()
	{
		func[0] = ')';	count = 2;
		func[1] = '(';	priority[1] = 0;
		func[2] = '+';	priority[2] = 1;
		func[3] = '-';	priority[3] = 1;
		func[4] = '*';	priority[4] = 2;
		func[6] = '=';	priority[6] = 0;
	}
}; 

class TPostfix
{
	string infix;      //инфиксна€ форма
	string postfix;    //постфиксна€ форма
	string* var;  //массив имен переменных
	size_t sizevar;    //предполагаемый размер массива переменных
	TablFunc operat;   //таблица с операци€ми
	double res;        //результат
	bool ProvWrongSymb();             //проверка на недопустимые символы
	bool ProvCountVarOp();            //проверка соответсви€ количества переменных и операций
	bool ProvCountSk();               //проверка скобок
	bool ProvInfix();                 //обща€ проверка инфиксной формы
	void AddVarMas();                 //выделение переменных и добавление в массив
	void DeleteSpaces(string s);   //удаление пробелов
public:
	// онстуртор
	TPostfix(string inf = "a+b");
	string ToPostfix();
	//Polynomial CalculatePolynom(THashTable<Polynomial> TableOfPolynom);
	double Calculate(); 
	//double Calculate(THashTable<Polynomial> TableOfPolynom);
	string* GetNameOfPolynom();
	//size_t GetNumOfPolynominals();	
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string* GetArrVar() { return var; }
	size_t GetCountOfVar() { return sizevar; }
	
	
	//double Calculate(); // ¬вод переменных, вычисление по постфиксной форме
};

#endif