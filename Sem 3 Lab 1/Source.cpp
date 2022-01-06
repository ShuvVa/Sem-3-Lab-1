#include <iostream>
//#include <math.h>
//#include <cmath>
#include <ctime>
#include <locale>
#include <vector>
#include <string>
//#include <windows.h>

#include "User.h"
#include "Diffie_Hellman.h"
#include "Shamir.h"
#include "ElGamal.h"
#include "RSA.h"

using namespace std;

string VARIABLE_NAME = "NULL";	//Переменная для содержания последнего имени пользователя
//
#define SAVE_VARIABLE_NAME(variable) VARIABLE_NAME = string(#variable);	//Для получения имени пользователя

void DH() 
{
	User Server;
	int g, p;
	Server.Generate_g_p(g, p);

	Diffie_Hellman Alice(g, p), Bob(g, p);

	SAVE_VARIABLE_NAME(Alice);
	Alice.SetUser_Name(VARIABLE_NAME);
	SAVE_VARIABLE_NAME(Bob);
	Bob.SetUser_Name(VARIABLE_NAME);

	Diffie_Hellman DataExchage(Alice, Bob);
	
	Alice.PrintData();
	Bob.PrintData();
}

void SH() 
{
	User Server;
	unsigned long long int p = Server.PrimeRandom(1000000, 10000000);

	Shamir Alice(p, true), Bob(p);
	//Shamir Alice(true, true), Bob(false, true);

	SAVE_VARIABLE_NAME(Alice);
	Alice.SetUser_Name(VARIABLE_NAME);
	SAVE_VARIABLE_NAME(Bob);
	Bob.SetUser_Name(VARIABLE_NAME);

	Alice.PrintData();

	Shamir DataExchange(Alice, Bob);

	Bob.PrintData();
}

void EL() 
{
	User Server;
	int g, p;
	Server.Generate_g_p(g, p);
	
	//ElGamal Alice(p,g,true, true), Bob(p,g,false, true);
	ElGamal Alice(p,g,true), Bob(p,g);

	SAVE_VARIABLE_NAME(Alice);
	Alice.SetUser_Name(VARIABLE_NAME);
	SAVE_VARIABLE_NAME(Bob);
	Bob.SetUser_Name(VARIABLE_NAME);

	Alice.PrintData();

	ElGamal ExchangeData(Alice, Bob);

	Bob.PrintData();
}

void Rsa() 
{
	RSA Alice(true), Bob(0);

	SAVE_VARIABLE_NAME(Alice);
	Alice.SetUser_Name(VARIABLE_NAME);
	SAVE_VARIABLE_NAME(Bob);
	Bob.SetUser_Name(VARIABLE_NAME);

	Alice.PrintData();

	RSA ExchangeData(Alice, Bob);

	Bob.PrintData();
}

int main() 
{
	setlocale(LC_ALL, "Rus");
	
	srand(time(0));
	//User Test;

	//DH();
	//SH();
	//EL();
	Rsa();

	//cout << "3^15 mod 7 = " << Test.Mod_Exp(3, 15, 7) << endl;
	//Test.Prime(2);
	//Test.Mod_Inverse(3, 11);
	//Test.Mod_Inverse(11, 7);
	//Test.GEA(11, 7);
	//Test.GEA(18, 9);
	//Test.GEA(2, 7);
	//int x = 0;
	//DH();

	//SH();

	//El();
	
	//cout << "Hello Привет";

	//cout << RoD_find(5, 4, 5) << endl;

	//cout << RoD_Diversity(40,20,11) << endl;

	//for (int i = 0; i < 100; i++) cout << "Time - " << time(0) << ": Generation result - " << PrimeRandom(2,100) << endl;

	//Prime(51);

	/*for (int i = 10; i <= 200; i += 10) {
		cout << (i+1) << ": " << Prime(1 + i) << endl;
	}*/
	/*int y = 0;
	if (y) cout << true << endl; else cout << false << endl;
	y++;
	if (y) cout << true << endl; else cout << false << endl;
	y = -1;
	if (y) cout << true << endl; else cout << false << endl;*/

	//cout << RoD_find(3, 3, 9) << endl;
}