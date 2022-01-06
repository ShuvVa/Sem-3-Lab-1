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
    CalcY();
}

Diffie_Hellman::Diffie_Hellman(Diffie_Hellman& first_user, Diffie_Hellman& second_user) 
{
    g = NULL;
    p = NULL;
    X = NULL;
    Y = NULL;
    Z = NULL;
    first_user.CalcZ(second_user.GetY());
    second_user.CalcZ(first_user.GetY());
}


void Diffie_Hellman::Setg(int _g) 
{
    g = _g;
}

void Diffie_Hellman::Setp(int _p) 
{
    p = _p;
}

void Diffie_Hellman::SetX(int _x) 
{
    X = _x;
}

void Diffie_Hellman::Generate_X() 
{
    X = Random(2, 1000);
}

int Diffie_Hellman::Getg() 
{
    return g;
}

int Diffie_Hellman::Getp() 
{
    return p;
}

int Diffie_Hellman::GetX() 
{
    return X;
}

int Diffie_Hellman::GetY() 
{
    return Y;
}

int Diffie_Hellman::GetZ() 
{
    return Z;
}

void Diffie_Hellman::CalcY() 
{
    Y = Mod_Exp(g, X, p);
}

void Diffie_Hellman::CalcZ(int _y) 
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