#pragma once
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

//string VARIABLE_NAME = "NULL";	//Переменная для содержания последнего имени пользователя
//
//#define SAVE_VARIABLE_NAME(variable) VARIABLE_NAME = string(#variable);	//Для получения имени пользователя

typedef tuple <int, int, int> TP;

class User {
public:

	//	Проверка на то является ли полученное функцией число простым: если x - простое, функция возвращает значение TRUE, если нет - FALSE
	bool Prime(const int);

	//	Генерация простого числа в пределах от begining до end
	int Random(int begining, int ending);

	//	Псевдогенератор простых чисел
	int PrimeRandom(int begining, int ending);
		
	TP RashAlgEv(int a, int b);
};