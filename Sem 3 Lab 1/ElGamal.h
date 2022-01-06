#pragma once
#include "User.h"

class ElGamal : public User
{
private:
    long long int g, p;
    Vector_1D_long_long_int c, d, k, r, message;
    Vector_1D_pair_long_long_int data;
    bool sender;
    //int message_size;

public:
    ElGamal();

    ElGamal(long long int _p, long long int _g, bool _sender = false);

    //ElGamal(long long int _p, long long int _g,bool _sender = false, bool _test = false);

    ElGamal(ElGamal& first_user, ElGamal& second_user);


    void Generate_c_d(int _message_size);

    void Generate_c_d(vector <long long int> _d);
    
    void Generate_k_r();

    int Get_message_size();

    Vector_1D_pair_long_long_int Get_data();

    Vector_1D_long_long_int Get_d();

    void Encrypt(Vector_1D_long_long_int _d);

    void Decrypt();

    void InsertMessage();

    void SetMessage(int _message);

    void SetMessage(string _message);

    void Set_p(long long int _p);

    void Set_g(long long int _g);

    void SetData();

    void SetData(Vector_1D_pair_long_long_int _data);

    void PrintData();

    ~ElGamal();
};

