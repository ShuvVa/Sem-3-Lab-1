#pragma once
#include "User.h"
//	Алгоритм шифрования RSA
class RSA : public User
{
private:
	Vector_1D_long_long_int p, q, n, fi, c, d;

public:
	//	Конструктор класса по умолчанию
	RSA();
	//	Конструктор класса для инициализации пользователя
	RSA(bool _sender = false);
	//	Конструктор класса для работы с отправителем и получателем
	RSA(RSA& first_user, RSA& second_user);

	//	Метод для генерации p
	void Generate_p();
	//	Метод для генерации p по полученному размеру сообщения
	void Generate_p(int _message_size);
	//	Метод для генерации q
	void Generate_q();
	//	Метод для генерации d
	void Generate_d();
	
	//	Метод для возвращения d
	Vector_1D_long_long_int Get_d();
	//	Метод для возвращения n
	Vector_1D_long_long_int Get_n();
	
	//	Метод для вычисления n
	void Calc_n();
	//	Метод для вычисления fi
	void Calc_fi();
	//	Метод для вычисления c
	void Calc_c();

	//	Метод для шифрования сообщения по принятым d и n
	void Encrypt(Vector_1D_long_long_int _d, Vector_1D_long_long_int _n);
	//	Метод для дешифрования сообщения
	void Decrypt();
	
	//	Метод для вывода данных класса
	void PrintData();

	//	Деструктор класса
	~RSA();
};

