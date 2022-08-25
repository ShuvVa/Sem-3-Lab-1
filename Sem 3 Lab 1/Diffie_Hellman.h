#pragma once
#include "User.h"

class Diffie_Hellman : public User {
 private:
  int g, p, X, Y, Z;

 public:
  //	Конструктор класса по умолчанию
  Diffie_Hellman();
  //	Конструктор класса для инициализации пользователя
  Diffie_Hellman(int _g, int _p);
  //	Конструктор класса для работы с отправителем и получателем
  Diffie_Hellman(Diffie_Hellman&, Diffie_Hellman&);

  //	Метод для установки g
  void Set_g(int);
  //	Метод для установки p
  void Set_p(int);
  //	Метод для установки X
  void Set_X(int);
  //	Метод для генерации X
  void Generate_X();
  //	Метод для получения g
  int Get_g();
  //	Метод для получения p
  int Get_p();
  //	Метод для получения X
  int Get_X();
  //	Метод для получения Y
  int Get_Y();
  //	Метод для получения Z
  int Get_Z();
  //	Метод для расчета Y
  void Calc_Y();
  //	Метод для расчета Z
  void Calc_Z(int);
  //	Метод для вывода данных класса
  void PrintData();

  //	Деструктор класса
  ~Diffie_Hellman();
};
