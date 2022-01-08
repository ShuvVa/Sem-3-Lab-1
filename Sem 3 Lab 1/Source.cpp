#include <ctime>
#include <locale>

#include "User.h"
#include "Diffie_Hellman.h"
#include "Shamir.h"
#include "ElGamal.h"
#include "RSA.h"

using namespace std;

string VARIABLE_NAME = "NULL";	//Переменная для содержания последнего имени пользователя
//
#define SAVE_VARIABLE_NAME(variable) VARIABLE_NAME = string(#variable);	//Для получения имени пользователя
//	Вызов тестового экзмемпляра работы алгоритма Диффи-Хеллмана
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
//	Вызов тестового экзмемпляра работы шифра Шамира
void SH() 
{
	User Server;
	unsigned long long int p = Server.PrimeRandom(1000000, 10000000);

	Shamir Alice(p, true), Bob(p);

	SAVE_VARIABLE_NAME(Alice);
	Alice.SetUser_Name(VARIABLE_NAME);
	SAVE_VARIABLE_NAME(Bob);
	Bob.SetUser_Name(VARIABLE_NAME);

	Alice.PrintData();

	Shamir DataExchange(Alice, Bob);

	Bob.PrintData();
}
//	Вызов тестового экзмемпляра работы шифра Эль-Гамаля
void EL() 
{
	User Server;
	int g, p;
	Server.Generate_g_p(g, p);
	
	ElGamal Alice(p,g,true), Bob(p,g);

	SAVE_VARIABLE_NAME(Alice);
	Alice.SetUser_Name(VARIABLE_NAME);
	SAVE_VARIABLE_NAME(Bob);
	Bob.SetUser_Name(VARIABLE_NAME);

	Alice.PrintData();

	ElGamal ExchangeData(Alice, Bob);

	Bob.PrintData();
}
//	Вызов тестового экзмемпляра работы шифра RSA
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
	
	char choice;
	cout << "Введите первую букву алгоритма для его запуска:\n D: Алгоритм Диффи-Хеллмана;\n S: Шифр Шамира;\n E: Шифр Эль-Гамаля;\n R: Шифр RSA.\n\n: ";
	cin >> choice;
	cout << endl;
	switch (choice)
	{

		case '1':
		{
			DH();
			break;
		}
		case '2':
		{
			SH();
			break;
		}
		case '3':
		{
			EL();
			break;
		}
		case '4':
		{
			Rsa();
			break;
		}
		case 'E':
		{
			EL();
			break;
		}
		case 'e':
		{
			EL();
			break;
		}
		case 'D':
		{
			DH();
			break;
		}
		case 'd':
		{
			DH();
			break;
		}
		case 'R':
		{
			Rsa();
			break;
		}
		case 'r':
		{
			Rsa();
			break;
		}
		case 'S':
		{
			SH();
			break;
		}
		case 's':
		{
			SH();
			break;
		}
		default: 
		{
			cout << "Вы ввели неправильный символ. До свидания." << endl ;
			break;
		}
		
	}
	
}