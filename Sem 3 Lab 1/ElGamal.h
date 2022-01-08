#pragma once
#include "User.h"

class ElGamal : public User
{
private:
    long long int g, p;
    Vector_1D_long_long_int c, d, k, r;
    Vector_1D_pair_long_long_int data;

public:
    //	Конструктор класса по умолчанию
    ElGamal();
    //	Конструктор класса для инициализации пользователя
    ElGamal(long long int _p, long long int _g, bool _sender = false);
    //	Конструктор класса для работы с отправителем и получателем
    ElGamal(ElGamal& first_user, ElGamal& second_user);

    //	Метод для генерации с и d по принятому размеру сообщения
    void Generate_c_d(int _message_size); 
    //	Метод для генерации k и r 
    void Generate_k_r();

    //  Метод для возвращения пар "ключ - закодированное сообщение"
    Vector_1D_pair_long_long_int Get_data();
    //  Метод для возвращения d
    Vector_1D_long_long_int Get_d();
    
    //	Метод для шифрования сообщения по принятому d
    void Encrypt(Vector_1D_long_long_int _d);
    //	Метод для дешифрования сообщения
    void Decrypt();
    
    //	Метод для установки полученного p
    void Set_p(long long int _p);
    //	Метод для установки полученного g
    void Set_g(long long int _g);
    //	Метод для задания пар "ключ - закодированное сообщение"
    void SetData();
    //	Метод для установки принятых пар "ключ - закодированное сообщение"
    void SetData(Vector_1D_pair_long_long_int _data);
    
    //	Метод для вывода данных класса
    void PrintData();

    //	Деструктор класса
    ~ElGamal();
};

