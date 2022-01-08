#pragma once
#include "User.h"

class Shamir : public User
{
private:
    long long int p;
    map <unsigned long long int, unsigned long long int> key;

public:
    //	Конструктор класса по умолчанию
    Shamir();
    //	Конструктор класса для инициализации пользователя
    Shamir(unsigned long long int _p, bool _sender = false);
    //	Конструктор класса для работы с отправителем и получателем
    Shamir(Shamir& first_user, Shamir& second_user);

    //  Метод для проверки наличия одинаковых ключей в словаре
    bool check_for_equal_keys(unsigned long long int _key);
    //  Метод для проверки наличия одинаковых значений в словаре
    bool check_for_equal_values(unsigned long long int _value);

    //  Метод для получения ключей словаря
    void Get_map_key(Vector_1D_long_long_int& _key);
    //  Метод для получения значений словаря
    void Get_map_value(Vector_1D_long_long_int& _value);
    //	Метод для генерации с и d по принятому размеру сообщения
    void Generate_key();
    
    //	Метод для шифрования принятого сообщения
    void Encode(Vector_1D_long_long_int _message);
    //	Метод для дешифрования принятого сообщения
    void Decode(Vector_1D_long_long_int _message);

    //	Метод для вывода данных класса
    void PrintData();

    //	Деструктор класса
    ~Shamir();
};

