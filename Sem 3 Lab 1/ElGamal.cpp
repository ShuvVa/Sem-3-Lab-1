#include "ElGamal.h"

ElGamal::ElGamal()
{
    g = NULL;
    p = NULL;
    c.push_back(NULL);
    d.push_back(NULL);
    r.push_back(NULL);
    message.push_back(NULL);
    data.push_back(make_pair(NULL, NULL));
    sender = false;
}

ElGamal::ElGamal(long long int _p, long long int _g, bool _sender)
{
    p = _p;
    g = _g;
    sender = _sender;
    if (sender)
    {
        InsertMessage();
        Generate_k_r();
    }

}

ElGamal::ElGamal(ElGamal& first_user, ElGamal& second_user) {
    p = NULL;
    g = NULL;
    sender = NULL;

    second_user.Generate_c_d(first_user.Get_Message_Size());

    first_user.Encrypt(second_user.Get_d());

    second_user.SetData(first_user.Get_data());

    second_user.Decrypt();
}



void ElGamal::Generate_c_d(int _message_size)
{
    c.clear();
    d.clear();
    int _c;
    for (unsigned int i = 0; i < _message_size; i++)
    {
        do {
            _c = Random(2, p - 1);
            if ((_c < p - 1) && (_c > 1))
            {
                c.push_back(_c);
                d.push_back(Mod_Exp(g, c[i], p));
                break;
            }
        } while (true);
    }
}

void ElGamal::Generate_k_r()
{
    k.clear();
    r.clear();
    int _k, _r;
    for (unsigned i = 0; i < message.size(); i++)
    {
        do {
            _k = Random(1, p - 2);
            if ((_k >= 1) && (_k <= p - 2)) break;
        } while (true);

        _r = Mod_Exp(g, _k, p);
        k.push_back(_k);
        r.push_back(_r);
    }
}

Vector_1D_pair_long_long_int ElGamal::Get_data()
{
    return data;
}

Vector_1D_long_long_int ElGamal::Get_d()
{
    return d;
}

void ElGamal::Encrypt(Vector_1D_long_long_int _d)
{
    for (unsigned int i = 0; i < message.size(); i++)
    {
        message[i] = Mod_Exp(message[i] * Mod_Exp(_d[i], k[i], p), 1, p);
    }

    SetData();
}

void ElGamal::Decrypt()
{
    r.clear();
    message.clear();

    for (unsigned int i = 0; i < data.size(); i++)
    {
        r.push_back(data[i].first); message.push_back(data[i].second);
        message[i] = Mod_Exp(message[i] * Mod_Exp(r[i], p - 1 - c[i], p), 1, p);
    }
}

void ElGamal::Set_p(long long int _p)
{
    p = _p;
}

void ElGamal::Set_g(long long int _g)
{
    g = _g;
}

void ElGamal::SetData()
{
    data.clear();

    for (unsigned int i = 0; i < message.size(); i++)
    {
        data.push_back(make_pair(r[i], message[i]));
    }
}

void ElGamal::SetData(Vector_1D_pair_long_long_int _data)
{
    data.clear();

    data = _data;
}

void ElGamal::PrintData() 
{
    cout << "Name: " << User_Name << endl;
    cout << "sender: " << sender << endl;
    cout << "g: " << g << endl;
    cout << "p: " << p << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    cout << "k: " << k << endl;
    cout << "r: " << r << endl;
    cout << "message: " << message << endl;
    cout << "converted message: " << Message_ToString() << endl;
    cout << "data: " << data << endl << endl;
}

ElGamal::~ElGamal()
{
    g = NULL;
    p = NULL;
    c.clear();
    d.clear();
    k.clear();
    r.clear();
    message.clear();
    data.clear();
    sender = NULL;
}