#pragma once
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <map>

//#include "Diffie_Hellman.h"
//#include "Shamir.h"

using namespace std;
//#define _GEA_tuple


typedef tuple <int, int, int> TP_int;

typedef vector<int> Vector_1D_int;

typedef vector < Vector_1D_int > Vector_2D_int;

typedef vector<long long> Vector_1D_long_long;

typedef vector<Vector_1D_long_long> Vector_2D_long_long;

ostream& operator<<(ostream& ostr, const Vector_1D_int& Vec_1d);

ostream& operator<<(ostream& ostr, const Vector_2D_int& Vec_2d);

ostream operator<<(ostream& ostr, map<int, int>& map_int);

//Класс, содержащий в себе основные методы, используемые при работе алгоритмов шифрования
class User {
protected: 
	string User_Name;
	
public:
	
	void SetUser_Name(string);

	//	Проверка на то является ли полученное функцией число простым: если x - простое, функция возвращает значение TRUE, если нет - FALSE
	bool Prime(const int);

	//	Генерация простого числа в пределах от begining до end
	int Random(int begining, int ending);

	//	Псевдогенератор простых чисел
	int PrimeRandom(int begining, int ending);

	//	Наибольший общий делитель/The greatest common divisor (GCD)
	long long GCD(long long firstNumber, long long secondNumber);
	
	//	Возведение в степень по модулю/Modular exponentiation
	long long Mod_Exp(long long base, long long power, long long divisor);

#ifdef _GEA_tuple
	//	Обобщенный алгоритм евклида/generalized euclid algorithm (GEA) (с использованием tuple)
	TP_int GEA_tuple(int firstNumber, int secondNumber);
#endif // _GEA_tuple

	//	Обобщенный алгоритм евклида / generalized euclid algorithm (GEA) (с использованием vector)
	Vector_2D_int GEA(int firstNumber, int secondNumber);

	// Инверсия числа по cd mod m = 1 или d = c^-1 mod m. firstNumbr - c, secondNumber - m
	long long Mod_Inverse(long long firstNumber, long long secondNumber);

};