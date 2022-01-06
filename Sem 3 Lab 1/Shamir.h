#pragma once
#include "User.h"

class Shamir : public User
{
private:
    long long int p;
    map <unsigned long long int, unsigned long long int> key;
    Vector_1D_int message;
    bool sender;

public:
    Shamir();

    Shamir(unsigned long long int _p, bool _sender = false);

    //Shamir(bool _sender = false, bool test = false);

    Shamir(Shamir& first_user, Shamir& second_user);


    bool check_for_equal_keys(unsigned long long int _key);

    bool check_for_equal_values(unsigned long long int _value);

    void Generate_key();

    void InsertMessage();

    Vector_1D_int GetMessage();

    void SetSender(bool _sender);

    void SetMessage(string _message);

    void SetMessage(unsigned long long int _message);

    void Encode(Vector_1D_int _message);

    void Decode(Vector_1D_int _message);

    void PrintData();

    ~Shamir();
};

