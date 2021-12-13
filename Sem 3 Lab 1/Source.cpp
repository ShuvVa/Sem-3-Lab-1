#include <iostream>
//#include <math.h>
//#include <cmath>
#include <ctime>
#include <locale>
#include <vector>
#include <string>
//#include <windows.h>

#include "User.h"

using namespace std;


//
//bool Prime(int x) {	//Проверка на то является ли полученное функцией число простым: если x - простое, функция возвращает значение TRUE, если нет - FALSE
//	if (x > 4) {
//		return ((x * x) % 24 == 1) ? true : false;
//	}
//	else {
//		vector <int> A;
//
//		for (int i = 2; i <= x; i++) {
//			A.push_back(i);
//		}
//
//		for (int i = 0; i < int(A.size()); i++) {
//			int j = 2;
//			while (j <= A[i]) {
//				if ((A[i] % j == 0) && (A[i] != j)) {
//					A[i] = 0;
//				}
//				j++;
//			}
//		}
//
//		int i = 0;
//		while (i<int(A.size())) {
//			if (A[i] == 0) {
//				A.erase(A.begin() + i);
//				i = 0;
//				continue;
//			}
//			i++;
//		}
//
//		return (x == A[A.size() - 1]) ? true : false;
//	}
//}
//
//int Random(int a, int b) {
//	int x = a + rand() % (b - a);
//	return x;
//}
//
//int PrimeRandom(int a, int b) {	//Псевдогенератор простых чисел
//	int x = 0;
//	/*while (!(Prime(x))) {
//		x = a + rand() % (b - a);
//	}*/
//
//	do {
//		x = a + rand() % (b - a);
//	} while (!(Prime(x)));
//
//	return x;
//}
//
//int RoD_find(int num, int pow, int mod) {	//Расширенный алгоритм Евклида для нахождения остатка от деления числа num в степени pow на число mod
//	//cout << "----------------------------------" << endl << "Проверка расширенного алгоритма Евклида на работоспособность" << endl << "Принятые значения: " << endl << "число (num) - " << num << ", степень числа (pow) - " << pow << ", делитель (num) - " << num << endl << endl;
//	/*pow = pow % (mod - 1);
//	num %= mod;*/
//	//cout << "Измененные значения:" << endl << "num = " << num << ", pow = " << pow << ", mod = " << mod << endl;
//	//cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << "Начало цикла для вычисления остатка от деления" << endl;
//	int result = 1;
//	//cout << "i < " << pow << endl;
//	for (int i = 1; i <= pow; i++) {
//		//cout << "i = " << i << endl;
//		//cout << result << " *= " << num << " = ";
//		result *= num;
//		//cout << result << endl << result << "%=" << mod << " = ";
//		result %= mod;
//		//cout << result << endl << endl;
//	}
//	//cout << "Конец цикла для вычисления остатка от деления" << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//	return(result);
//}
//
//bool RoD_Diversity(int g, int p, int pow = 20) {		//Функция для проверки разнообразия остатков от деления g mod p в различных степенях (от 1 до pow)
//	int length = 0;
//	vector <int> a;
//
//	//cout << "Incert g, pow, p" << endl;
//	//cin >> g >> pow >> p;
//
//	a.resize(pow);
//
//	for (int i = 0; i < pow; i++) {
//		a[i] = RoD_find(g, i + 1, p);
//		//cout << "g^pow mod p = " << g << "^" << i + 1 << " mod " << p << " = " << a[i] << endl;
//	}
//
//	for (int i = 1; ((i < pow) && (a[i] != a[0])); i++) {
//		length++;
//	}
//
//	//if (length <= 5) cout << "Промежуток между повторяющимися остатками слишком мал." << endl;
//	//else cout << "Промежуток между повторяющимися остатками достаточно велик." << endl;
//	return !(length <= 7);
//}
//
//int gcd(int x, int y) {	//Нахождение НОД
//	return y ? gcd(y, x % y) : x;
//}
//
//int MPN(int p, int a = 1) {	//Функция по поиску такого взаимно простого числа для a, что (a * b) % (p - 1) = 1
//	int b = 2;
//	while ((a * b) % (p - 1) != 1) {
//		b++;
//	}
//	return b;
//}
//
//int pow(int a, int b) {
//	if (b < 0) return 0;
//	int n = 1;
//	for (int i = 0; i < b; i++)
//		n *= a;
//	return n;
//}
//
//class User {
//public:
//	class Diffi_Hellman {
//	private:
//		int g, p, x, X, K;
//	public:
//		Diffi_Hellman() {
//			g = 0;
//			p = 0;
//			x = 0;
//			X = 0;
//			K = 0;
//		}
//
//		friend int RoD_find(int num, int pow, int mod);
//
//		friend int PrimeRandom(int a, int b);
//
//		void Get_g_p(int w, int z) {
//			g = w;
//			p = z;
//		}
//
//		void Get_x(int y) {
//			x = y;
//		}
//
//		void Generate_x() {
//			x = PrimeRandom(2, 100);
//		}
//
//		int StepOne() {
//			X = RoD_find(g, x, p);
//			return X;
//		}
//
//		void StepTwo(int A) {
//			K = RoD_find(A, x, p);
//			//return K;
//		}
//
//
//
//		void Out(string name) {
//			cout << "Name: " << name << endl;
//			cout << "g = " << g << endl;
//			cout << "p = " << p << endl;
//			cout << "x = " << x << endl;
//			cout << "X = " << X << endl;
//			cout << "K = " << K << endl << endl;
//		}
//
//		~Diffi_Hellman() {
//			g = 0;
//			p = 0;
//			x = 0;
//			X = 0;
//			K = 0;
//		}
//
//	};
//
//	class Shamir {
//	private:
//		int p, message, x, y, message_N, message_fi_N;
//		bool sender;
//	public:
//		Shamir() {
//			p = 0;
//			message = 0;
//			x = 0;
//			y = 0;
//			message_N = 0;
//			message_fi_N = 0;
//			sender = 0;
//		}
//
//		friend int RoD_find(int num, int pow, int mod);
//
//		friend int PrimeRandom(int a, int b);
//
//		friend int MPN(int p, int a);
//
//		void Generate_message() {
//			message = PrimeRandom(2, 100);
//		}
//
//		void Get_sender(bool a) {
//			sender = a;
//		}
//
//		void Generate_x_y() {
//			do {
//				x = PrimeRandom(20, 50);
//				y = MPN(p, x);
//			} while ((RoD_find(x * y, 1, p - 1) != 1) || (gcd(x, p - 1) != 1) || (x == y));
//		}
//
//		void Get_x_Generate_y(int a) {
//			x = a;
//			y = MPN(p, x);
//			while ((RoD_find(x * y, 1, p - 1) != 1) || (gcd(x, p - 1) != 1) || (x == y)) {
//				cout << "x and p-1 are not mutually prime numbers. Please enter x again: ";
//				cin >> x;
//				y = MPN(p, x);
//			}
//
//		}
//
//		void Get_message(int a) {
//			if (a >= p) {
//				cout << "You entered wrong number. Please try again: ";
//				cin >> a;
//			}
//			message = a;
//		}
//
//		void Get_p(int a) {
//			p = a;
//		}
//
//		int Give_x() {
//			return x;
//		}
//
//		int Give_message() {
//			return message;
//		}
//
//		int Crypt(int X) {
//			if (!(message)) message = X;
//			message_N = RoD_find(X, x, p);
//			return message_N;
//		}
//
//		int Decrypt(int X) {
//			message_fi_N = RoD_find(X, y, p);
//			return message_fi_N;
//		}
//
//		void Out(string name) {
//			cout << ((sender) ? "Sender:" : "Host:") << endl;
//			cout << "Name: " << name << endl;
//
//			if (sender) cout << "Sent message - message = " << message << endl;
//			cout << "p = " << p << endl;
//
//			cout << "x = " << x << endl;
//			cout << "y = " << y << endl;
//
//			cout << "message_N = message^x mod p = " << message << "^" << x << " mod " << p << " = " << message_N << endl;
//			cout << "message_fi_N = message_N^y mod p = " << message_N << "^" << y << " mod " << p << " = " << message_fi_N;
//			if (!(sender)) cout << " - Recieved message";
//			cout << endl << endl << endl;
//		}
//
//		~Shamir() {
//			p = 0;
//			message = 0;
//			x = 0;
//			y = 0;
//			message_N = 0;
//			message_fi_N = 0;
//			sender = 0;
//		}
//	};
//
//	class Elgamal {
//	private:
//		int p, g, x, y, k, r;
//		vector <int> encrypt, decrypt;
//		string M;
//	public:
//		Elgamal() {
//			p = 0;
//			g = 0;
//			x = 0;
//			y = 0;
//			k = 0;
//			r = 0;
//			encrypt = {0};
//			decrypt = { 0 };
//			M = "";
//		}
//
//		friend int RoD_find(int num, int pow, int mod);
//
//		friend int MPN(int p, int a);
//		
//		friend int Random(int a, int b);
//
//		void Get_message() {
//			cin.ignore(32767, '\n');
//			string a;
//			cout << "Введите передаваемое сообщение: " << endl;
//			//cin >> a;
//			getline(cin, a);
//			
//			M = a;
//		}
//
//		void Get_p_g(int P, int G) {
//
//			p = P;
//			g = G;
//		}
//
//		void Get_x(string name = "Default") {
//			int X;
//			cout << endl << "Подьзователь " << name << endl;
//			cout << "Введите значение x: " << endl;
//			cin >> X;
//			while ((X<=1)||(X >= (p - 1))) {
//				cout << "x не соответствует условию 1<x<(p-1) (1<x<" << p << "-1). Попробуйте ввести другое значение x: ";
//				cin >> X;
//			}
//			x = X;
//		}
//
//		void Get_k(string name = "Default") {
//			int K;
//			cout << endl <<"Подьзователь " << name << endl;
//			cout << "Введите значение k: " << endl;
//			cin >> K;
//			while ((K <= 1) || (K >= (p - 1))) {
//				cout << "k не соответствует условию 1<k<(p-1) (1<k<" << p << "-1). Попробуйте ввести другое значение k: ";
//				cin >> K;
//			}
//			k = K;
//		}
//
//		void Generate_x() {
//			do {
//				x = Random(2, 100);
//			} while (x >= (p - 1));
//		}
//
//		void Generate_y() {
//			y = RoD_find(g, x, p);
//		}
//
//		void Generate_k() {
//			do {
//				k = Random(2, 100);
//			} while (((gcd(k, (p - 1))) != 1)||(k>=(p-1)));
//		}
//
//		int Give_y() {
//			return y;
//		}
//
//		int Give_r() {
//			return r = RoD_find(g, k, p);
//		}
//
//		vector <int> Encode(int Y) {
//			encrypt.resize(M.size());
//		//int n = pow(Y, k);
//		for (int i=0; i<M.size(); i++)
//			encrypt[i] = (int(M[i]) * RoD_find(Y, k, p))%p;
//			
//		/*int i = 0;
//		do {
//			encrypt +=  RoD_find(M[i] * Y, k, p);
//			i++;
//		} while (encrypt.size()<M.size());*/
//
//		return encrypt;
//		}
//
//		string Decode(vector<int> E, int R) {
//			decrypt.resize(E.size());
//			M.resize(E.size());
//				//int n = pow(R, (p - 1 - x));
//				//M = E * RoD_find(R, p-1-x, p);
//			for (int i = 0;i<M.size();i++)
//				decrypt[i] = (E[i] * RoD_find(R, p - 1 - x,p))%p;
//
//			for (int i = 0; i < decrypt.size(); i++)
//				M += char(decrypt[i]);
//			/*int i = 0;
//			do {
//				M += RoD_find(E[i] * R, p - 1 - x, p);
//			} while (M.size() < E.size());*/
//			return M;
//		}
//
//		void Out(string name) {
//			cout << "Name: " << name << endl;
//			cout << "p = " << p << endl;
//			cout << "g = " << g << endl;
//			cout << "x = " << x << endl;
//			cout << "y = " << y << endl;
//			cout << "k = " << k << endl;
//			cout << "r = " << r << endl;
//			for (int i=0;i<encrypt.size();i++)
//				cout << "encrypt = " << encrypt[i] << endl;
//			for (int i = 0; i < decrypt.size(); i++)
//				cout << "decrypt = " << decrypt[i] << endl;
//			cout << "M = " << M << endl;
//		}
//
//		~Elgamal() {
//			p = 0;
//			g = 0;
//			x = 0;
//			y = 0;
//			k = 0;
//			r = 0;
//			encrypt = {0};
//			decrypt = { 0 };
//			M = "";
//		}
//	};
//};
//
//void DH() {	//Диффи-Хеллман
//	/*int g = 7, p = 11;
//	int a = 3, A = 0, KA = 0;
//	int b = 6, B = 0, KB = 0;
//	A = RoD_find(g, a, p);
//	B = RoD_find(g, b, p);
//	cout << A << " " << B << endl;
//	KA = RoD_find(B, a, p);
//	KB = RoD_find(A, b, p);
//	cout << KA << " " << KB << endl;*/
//
//	int g = PrimeRandom(2, 100), p = PrimeRandom(2, 100);	//Генерация g - основания и p - делителя
//	//int g = 7, p = 11;
//	User::Diffi_Hellman Alice, Bob;	//Объявление действующих пользователей
//
//	Alice.Get_g_p(g, p);	//Присваивание пользователю значений переменных g и p
//	Bob.Get_g_p(g, p);
//
//	Alice.Generate_x();	//Генерация x для каждого пользователя (в текущем случае, условные a и b - соответственно)
//	Bob.Generate_x();
//
//	//Alice.Get_x(3);
//	//Bob.Get_x(6);
//
//	Alice.StepTwo(Bob.StepOne());	//Процесс обмена частными открытыми ключами между пользователями для получения секретного ключа
//	Bob.StepTwo(Alice.StepOne());
//
//	SAVE_VARIABLE_NAME(Alice);	//Вывод результатов работы
//	Alice.Out(VARIABLE_NAME);
//	SAVE_VARIABLE_NAME(Bob);
//	Bob.Out(VARIABLE_NAME);
//
//	//SAVE_VARIABLE_NAME(Alice);	//Вывод результатов работы
//	//Alice.Out(VARIABLE_NAME);
//	//SAVE_VARIABLE_NAME(Bob);
//	//Bob.Out(VARIABLE_NAME);
//}
//
//void SH() {
//	//int m = 100;
//	//int a = 17, p = 557, d = MPN(a, p);
//
//	//int b = 19, c = MPN(b, p);
//
//	//int m = PrimeRandom(2,1000);
//	//int p = PrimeRandom(1000, 2000);
//	//int a = PrimeRandom(2, 100), d = MPN(a, p);
//	//int b = PrimeRandom(2, 100), c = MPN(b, p);
//
//	///*float n, l;
//	//n = (d * a - 1) / (p - 1);
//	//l = (c * b - 1) / (p - 1);*/
//
//	//int E_a, D_a;
//	//int E_b, D_b;
//
//	//E_a = RoD_find(m, a, p);
//	//E_b = RoD_find(E_a, b, p);
//	//D_a = RoD_find(E_b, d, p);
//	//D_b = RoD_find(D_a, c, p);
//
//	//cout << "Начальное сообщение - m = " << m << endl;
//	//cout << "p = " << p << endl;
//
//	//cout << "a = " << a << endl;
//	//cout << "НОД(a,p-1) = " << "НОД(" << a << "," << p - 1 << ") = " << gcd(a, p - 1) << endl;
//	//cout << "d = " << d << endl;
//	////cout << "n = " << n << ", d*a = 1+n(p-1) - " << ((d*a)==(1+round(n)*(p-1))) << endl << endl;
//
//	//cout << "b = " << b << endl;
//	//cout << "НОД(b,p-1) = " << "НОД(" << b << "," << p - 1 << ") = " << gcd(b, p - 1) << endl;
//	//cout << "c = " << c << endl;
//	////cout << "l = " << l << ", c*b = 1+l(p-1) - " << ((c * b) == (1 + round(l) * (p - 1))) << endl << endl;
//
//	//cout << "E_a = m^a mod p = " << m << "^" << a << " mod " << p << " = " << E_a << endl;
//	//cout << "E_b = E_a^b mod p = " << E_a << "^" << b << " mod " << p << " = " << E_b << endl;
//	//cout << "D_a = E_b^d mod p = " << E_b << "^" << d << " mod " << p << " = " << D_a << endl;
//	//cout << "Переданное сообщение - D_b = D_a^c mod p = " << D_a << "^" << c << " mod " << p << " = " << D_b << endl;
//
//	//int p = PrimeRandom(100, 200);
//
//	int p = 23;
//	//int p = 3;
//
//	User::Shamir Alice, Bob;
//
//	Alice.Get_p(p);
//	Bob.Get_p(p);
//
//	//Alice.Generate_message();
//	Alice.Get_message(10);	//14*23^2+13
//	//Alice.Get_message(341);
//	//Alice.Get_message(1277);	//55*23+11+1=(1*23+22)*23+11+1
//	//Alice.Get_message(16777233);	//2^24+17
//	//Alice.Get_message(5764801);
//	//Alice.Get_message(20);
//	//Alice.Get_message(326);
//	Alice.Get_sender(true);
//
//	//Alice.Message_unification();
//
//	//Alice.Generate_x_y();
//	//Bob.Generate_x_y();
//
//	Alice.Get_x_Generate_y(7);
//	Bob.Get_x_Generate_y(5);
//
//	Bob.Decrypt(Alice.Decrypt(Bob.Crypt(Alice.Crypt(Alice.Give_message()))));
//
//	SAVE_VARIABLE_NAME(Alice);	//Вывод результатов работы
//	Alice.Out(VARIABLE_NAME);
//	SAVE_VARIABLE_NAME(Bob);
//	Bob.Out(VARIABLE_NAME);
//}
//
//void El() {
//	User::Elgamal Alice, Bob;
//
//	//int g = Random(2, 100), p = PrimeRandom(20, 100);
//
//	int p, g;
//	cout << "Введите p и g :" << endl;
//	cin >> p >> g;
//	while (!(Prime(p))) {
//		cout << "Число p не является простым. Попробуйте ввести другое значение p: " << endl;
//		cin >> p;
//	}
//
//	while (!(RoD_Diversity(g, p))) {
//		cout << "Число g имеет слишком маленький промежуток между повторяющимися остатками. Попробуйте ввести другое значение g: " << endl;
//		cin >> g;
//		//g = Random(2, 100);
//	}
//
//	Alice.Get_p_g(p, g);
//	Bob.Get_p_g(p, g);
//
//	Alice.Get_message();
//
//	/*Alice.Generate_x();
//	Bob.Generate_x();*/
//	SAVE_VARIABLE_NAME(Alice);
//	Alice.Get_x(VARIABLE_NAME);
//	SAVE_VARIABLE_NAME(Bob);
//	Bob.Get_x(VARIABLE_NAME);
//
//	Alice.Generate_y();
//	Bob.Generate_y();
//
//	/*Alice.Generate_k();*/
//	SAVE_VARIABLE_NAME(Alice);
//	Alice.Get_k(VARIABLE_NAME);
//
//	int r = Alice.Give_r();
//	vector<int> s = Alice.Encode(Bob.Give_y());
//
//	cout << "Полученное сообщение: " << Bob.Decode(s, r) << endl;
//
//
//	SAVE_VARIABLE_NAME(Alice);	//Вывод результатов работы
//	Alice.Out(VARIABLE_NAME);
//	SAVE_VARIABLE_NAME(Bob);
//	Bob.Out(VARIABLE_NAME);
//
//}



int main() {
	setlocale(LC_ALL, "Rus");
	//SetConsoleCP(1251);
	srand(time(0));
	User Test;

	//Test.Prime(2);
	Test.GEA(28, 19);
	int x = 0;
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