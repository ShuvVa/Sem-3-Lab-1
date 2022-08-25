#pragma once
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
//#define _GEA_tuple

//	Блок для удобства использования в программе

typedef tuple<int, int, int> TP_int;
typedef vector<int> Vector_1D_int;
typedef vector<long long> Vector_1D_long_long;
typedef vector<long long int> Vector_1D_long_long_int;
typedef vector<pair<long long int, long long int>> Vector_1D_pair_long_long_int;
typedef vector<Vector_1D_int> Vector_2D_int;
typedef vector<Vector_1D_long_long> Vector_2D_long_long;
typedef vector<Vector_1D_long_long_int> Vector_2D_long_long_int;

//	Перегрузка операторов вывода для вывода векторов

ostream& operator<<(ostream& ostr, const Vector_1D_int& Vec_1d);
ostream& operator<<(ostream& ostr, const Vector_1D_long_long& Vec_1d);
ostream& operator<<(ostream& ostr, const Vector_2D_int& Vec_2d);
ostream& operator<<(ostream& ostr, const Vector_2D_long_long& Vec_2d);
ostream& operator<<(ostream& ostr,
                    const Vector_1D_pair_long_long_int& Vec_pair);

//	Класс, содержащий в себе основные методы, используемые при работе
//алгоритмов шифрования
class User {
 protected:
  //	Имя пользователя
  string User_Name;
  //	Тип пользователя (отправитель - true/получатель - false)
  bool sender;
  //	Передаваемое сообщение
  Vector_1D_long_long_int message;

 public:
  //	Метод для установки имени пользователя
  void SetUser_Name(string);
  //	Метод для установки типа пользователя (отправитель/принимающий)
  void SetSender(bool _sender);

  //	Метод для возвращения размера сообщения
  int Get_Message_Size();
  //	Метод для возвращения сообщения
  Vector_1D_long_long_int Get_Message();
  //	Метод для выбора типа сообщения и его ввода
  void InsertMessage();
  //	Метод для установки числового сообщения
  void SetMessage(unsigned long long int _message);
  //	Метод для установки строкового сообщения
  void SetMessage(string _message);
  //	Метод для установки сообщения от другого пользователя
  void SetMessage(Vector_1D_long_long_int _message);
  //	Метод для конвертации сообщения в строку
  string Message_ToString();

  //	Проверка на то является ли полученное функцией число простым: если x -
  //простое, функция возвращает значение TRUE, если нет - FALSE
  bool Prime(const int);
  //	Генерация простого числа в пределах от begining до end
  int Random(int begining, int ending);
  //	Псевдогенератор простых чисел
  int PrimeRandom(int begining, int ending);

  //	Генератор g и p
  void Generate_g_p(int& g, int& p);

  //	Наибольший общий делитель/The greatest common divisor (GCD)
  long long GCD(long long firstNumber, long long secondNumber);
  //	Возведение в степень по модулю/Modular exponentiation
  long long Mod_Exp(long long base, long long power, long long divisor);
#ifdef _GEA_tuple
  //	Обобщенный алгоритм евклида/generalized euclid algorithm (GEA) (с
  //использованием tuple)
  TP_int GEA_tuple(int firstNumber, int secondNumber);
#endif  // _GEA_tuple
        //	Обобщенный алгоритм евклида / generalized euclid algorithm (GEA)
        //(с использованием vector)
  Vector_2D_int GEA(int firstNumber, int secondNumber);
  // Инверсия числа по cd mod m = 1 или d = c^-1 mod m. firstNumbr - c,
  // secondNumber - m
  long long Mod_Inverse(long long firstNumber, long long secondNumber);
};