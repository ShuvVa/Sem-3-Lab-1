#pragma once
#include "User.h"

class Diffie_Hellman : public User
{
private:
    int g, p, X, Y, Z;

public:
  
    Diffie_Hellman();

    Diffie_Hellman(int _g, int _p);

    Diffie_Hellman(Diffie_Hellman&, Diffie_Hellman&);
    
    void Setg(int);

    void Setp(int);

    void SetX(int);

    void Generate_X();

    int Getg();

    int Getp();

    int GetX();

    int GetY();

    int GetZ();

    void CalcY();

    void CalcZ(int);

    void PrintData();

    ~Diffie_Hellman();
};

