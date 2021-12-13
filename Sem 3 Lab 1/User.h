#pragma once
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
//#define _GEA_tuple
//string VARIABLE_NAME = "NULL";	//Переменная для содержания последнего имени пользователя
//
//#define SAVE_VARIABLE_NAME(variable) VARIABLE_NAME = string(#variable);	//Для получения имени пользователя

typedef tuple <int, int, int> TP;

//template<class T> 
//using Vector_1D = vector<T>; 
//
//template<class T>
//using Vector_2D = vector<vector<T>>;
//
//typedef Vector_2D < Vector_1D < int > > Vector_2D_int;

typedef vector<int> Vector_1D_int;

typedef vector < Vector_1D_int > Vector_2D_int;


ostream& operator<<(ostream& ostr, const Vector_1D_int& Vec_1d);

ostream& operator<<(ostream& ostr, const Vector_2D_int& Vec_2d);

//Класс, содержащий в себе основные методы, используемые при работе алгоритмов шифрования
class User {
	
public:

	//	Проверка на то является ли полученное функцией число простым: если x - простое, функция возвращает значение TRUE, если нет - FALSE
	bool Prime(const int);

	//	Генерация простого числа в пределах от begining до end
	int Random(int begining, int ending);

	//	Псевдогенератор простых чисел
	int PrimeRandom(int begining, int ending);

	

#ifdef _GEA_tuple
	//	Обобщенный алгоритм евклида/generalized euclid algorithm (GEA) (с использованием tuple)
	TP GEA_tuple(int firstNumber, int secondNumber);
#endif // _GEA_tuple

	//	Обобщенный алгоритм евклида/generalized euclid algorithm (GEA) (с использованием vector)
	Vector_1D_int GEA(int firstNumber, int secondNumber);

	
};