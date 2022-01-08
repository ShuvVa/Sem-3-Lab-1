#include "Diffie_Hellman.h"

Diffie_Hellman::Diffie_Hellman() 
{
    g = NULL;
    p = NULL;
    X = NULL;
    Y = NULL;
    Z = NULL;
}

Diffie_Hellman::Diffie_Hellman(int _g, int _p) 
{
    g = _g;
    p = _p;
    Generate_X();
    Y = NULL;
    Z = NULL;
    Calc_Y();
}

Diffie_Hellman::Diffie_Hellman(Diffie_Hellman& first_user, Diffie_Hellman& second_user) 
{
    g = NULL;
    p = NULL;
    X = NULL;
    Y = NULL;
    Z = NULL;

    first_user.Calc_Z(second_user.Get_Y());
    second_user.Calc_Z(first_user.Get_Y());
}


void Diffie_Hellman::Set_g(int _g) 
{
    g = _g;
}

void Diffie_Hellman::Set_p(int _p) 
{
    p = _p;
}

void Diffie_Hellman::Set_X(int _x) 
{
    X = _x;
}

void Diffie_Hellman::Generate_X() 
{
    X = Random(2, 1000);
}

int Diffie_Hellman::Get_g() 
{
    return g;
}

int Diffie_Hellman::Get_p() 
{
    return p;
}

int Diffie_Hellman::Get_X() 
{
    return X;
}

int Diffie_Hellman::Get_Y() 
{
    return Y;
}

int Diffie_Hellman::Get_Z() 
{
    return Z;
}

void Diffie_Hellman::Calc_Y() 
{
    Y = Mod_Exp(g, X, p);
}

void Diffie_Hellman::Calc_Z(int _y) 
{
    Z = Mod_Exp(_y, X, p);
}

void Diffie_Hellman::PrintData() 
{
    cout << "Name: " << User_Name << endl;
    cout << "g: " << g << endl;
    cout << "p: " << p << endl;
    cout << "X: " << X << endl;
    cout << "Y: " << Y << endl;
    cout << "Z: " << Z << endl << endl;
}

Diffie_Hellman::~Diffie_Hellman() 
{
    User_Name = "";
    p = NULL;
    g = NULL;
    X = NULL;
    Y = NULL;
    Z = NULL;
}