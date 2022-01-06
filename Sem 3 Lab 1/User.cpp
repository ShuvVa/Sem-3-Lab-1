#include "User.h"

ostream& operator<<(ostream& ostr, const Vector_1D_int& Vec_1d) 
{
	ostr << "{ ";
	for (unsigned int i = 0; i < Vec_1d.size(); i++)
		ostr << Vec_1d[i] << " ";
	ostr << "}";

	return ostr;
}

ostream& operator<<(ostream& ostr, const Vector_1D_long_long& Vec_1d)
{
	ostr << "{ ";
	for (unsigned int i = 0; i < Vec_1d.size(); i++)
		ostr << Vec_1d[i] << " ";
	ostr << "}";

	return ostr;
}

//ostream& operator<<(ostream& ostr, const Vector_1D_long_long_int& Vec_1d)
//{
//	ostr << "{ ";
//	for (unsigned int i = 0; i < Vec_1d.size(); i++)
//		ostr << Vec_1d[i] << " ";
//	ostr << "}";
//
//	return ostr;
//}

ostream& operator<<(ostream& ostr, const Vector_2D_int& Vec_2d) 
{
	for (unsigned int i = 0; i < Vec_2d.size(); i++) 
	{
		ostr << "{ ";
		for (unsigned int j = 0; j < Vec_2d[i].size(); j++)
			ostr << Vec_2d[i][j] << " ";
		ostr << "}";
		if (!(i == Vec_2d.size() - 1)) ostr << ",";
		
		ostr << "\n";

	}
		
	return ostr;
}

ostream& operator<<(ostream& ostr, const Vector_2D_long_long& Vec_2d)
{
	for (unsigned int i = 0; i < Vec_2d.size(); i++)
	{
		ostr << "{ ";
		for (unsigned int j = 0; j < Vec_2d[i].size(); j++)
			ostr << Vec_2d[i][j] << " ";
		ostr << "}";
		if (!(i == Vec_2d.size() - 1)) ostr << ",";

		ostr << "\n";

	}

	return ostr;
}

//ostream& operator<<(ostream& ostr, const Vector_2D_long_long_int& Vec_2d)
//{
//	for (unsigned int i = 0; i < Vec_2d.size(); i++)
//	{
//		ostr << "{ ";
//		for (unsigned int j = 0; j < Vec_2d[i].size(); j++)
//			ostr << Vec_2d[i][j] << " ";
//		ostr << "}";
//		if (!(i == Vec_2d.size() - 1)) ostr << ",";
//
//		ostr << "\n";
//
//	}
//
//	return ostr;
//}

ostream& operator<<(ostream& ostr, const Vector_1D_pair_long_long_int& Vec_pair) {

	ostr << "{ ";
	for (unsigned int i = 0; i < Vec_pair.size(); i++) 
	{
		ostr << Vec_pair[i].first << ": " << Vec_pair[i].second << " ";
	}
	ostr << "}";

	return ostr;
}

//ostream operator<<(ostream& ostr, map<int, int>& map_int) 
//{
//	Vector_1D_int k, v;
//	k.reserve(map_int.size());
//	v.reserve(map_int.size());
//
//	for (map<int, int>::iterator i = map_int.begin(); i != map_int.end(); ++i)
//	{
//		k.push_back(i->first);
//		v.push_back(i->second);
//	}
//
//	ostr << "{ ";
//	for (map<int, int>::iterator i = map_int.begin(); i != map_int.end(); ++i) {
//		ostr << to_string(i->first) << ": " << to_string(i->second) << " ";
//	}
//	for (unsigned int i = 0; i < map_int.size(); i++)
//		ostr << k[i] << ": " << v[i] << " ";
//
//
//	ostr << "}";
//
//	return ostr;
//}

void User::SetUser_Name(string _str) 
{
	User_Name = _str;
}

bool User::Prime(const int number) 
{
	//	¬ случае, если number больше 4, то используем свойство простых чисел, больше или равных 5 - при возведении во вторую степень и вз€тии отстатка от делени€ на 24, остаток всегда будет 1. ≈сли number меньше или равно 4
	//if (number > 4) {
	//	return ((number * number) % 24 == 1);
	//}
	//else {
	//	vector <int> Numbers;
	//	//	»нициализаци€ элементов вектора посредством помещени€ в него массива чисел от 2 до number включительно
	//	for (int i = 2; i <= number; i++) {
	//		Numbers.push_back(i);
	//	}
	//	//	ѕроверка на то, €вл€етс€ ли число простым - если нет, оно замен€етс€ нулем
	//	for (int i = 0; i < int(Numbers.size()); i++) {
	//		int j = 2;
	//		while (j <= Numbers[i]) {
	//			if ((Numbers[i] % j == 0) && (Numbers[i] != j)) {
	//				Numbers[i] = 0;
	//			}
	//			j++;
	//		}
	//	}
	//	//	”борка нулей из массива
	//	int i = 0;
	//	while (i<int(Numbers.size())) {
	//		if (Numbers[i] == 0) {
	//			Numbers.erase(Numbers.begin() + i);
	//			i = 0;
	//			continue;
	//		}
	//		i++;
	//	}
	//	//	≈сли последний элемент массива равно number, возращаетс€ значение TRUE, в ином случае - FALSE
	//	return (number == Numbers[Numbers.size() - 1]);
	//}
	auto sqrt_number = sqrt(number) + 1;
	for (unsigned int i = 2; i < sqrt_number; i++) 
	{
		if (number % i == 0) return false;
	}


	return true;
}

int User::Random(int begining, int ending) 
{
	return (begining + rand() % (ending - begining));
}

int User::PrimeRandom(int begining, int ending) 
{	
	int number = 0;

	do 
	{
		number = begining + rand() % (ending - begining);
	} while (!(Prime(number)));

	return number;
}

void User::Generate_g_p(int& g, int& p) 
{
	do 
	{
		p = PrimeRandom(1000000, 10000000);
		//auto q = PrimeRandom(3, 1000);
		//p = 2 * q + 1;
		auto q = (p - 1) / 2;
		g = Random(2, p-1);
		//g = Mod_Inverse()
		if ((g < p - 1) && (Mod_Exp(g, q, p) != 1)&&(GCD(g,p)==1)) break;
	} while (true);
}

long long User::GCD(long long firstNumber, long long secondNumber) 
{
	return secondNumber ? GCD(secondNumber, firstNumber % secondNumber) : firstNumber;
}

long long User::Mod_Exp(long long base, long long power, long long divisor) 
{
	//static int level;
	//cout << "Level: " << level << ": base = " << base << ", power = " << power << ", divisor = " << divisor << endl;
	//level++;

	return (!power) ? (1 % divisor) : ((power % 2 == 1) ? ((Mod_Exp(base, power - 1, divisor) * base) % divisor) : Mod_Exp((base * base) % divisor, power / 2, divisor));
}

Vector_2D_int User::GEA(int firstNumber, int secondNumber) 
{
	//firstNumber*x+secondNumber*y=GCD(firstNumber,secondNumber)
	
	Vector_2D_int Matrix = 
	{
		{firstNumber,1,0},//U
		{secondNumber,0,1}//V
	};
	
	//cout << Matrix << endl;
	
	for (int i = 0, q = 0; Matrix[1][0]!=0;i++) 
	{
		q = Matrix[0][0] / Matrix[1][0];
		Vector_1D_int Temp = { Matrix[0][0] % Matrix[1][0] , Matrix[0][1] - q * Matrix[1][1], Matrix[0][2] - q * Matrix[1][2] };
		Matrix[0] = Matrix[1];
		Matrix[1] = Temp;
	}
	//U(GCD(firstNumber,secondNumber),firstNumber,secondNumber)
	// U(GCD(firstNumber,secondNumber),x,y)
	//cout << Matrix[0] << endl;
	//cout << Matrix[1];
	//cout << Matrix;

	//cout << GCD(firstNumber, secondNumber);

	return Matrix;
}

long long User::Mod_Inverse(long long firstNumber, long long secondNumber) 
{
	auto u = make_pair(secondNumber, 0);
	auto v = make_pair(firstNumber, 1);
	for (; v.first > 0;) 
	{
		auto q = u.first / v.first;
		auto t = make_pair(u.first % v.first, u.second - q * v.second);
		u = v;
		v = t;
	}
	if (u.second < 0) u.second += secondNumber;
	return u.second;
}

#ifdef _GEA_tuple
TP_int User::GEA_tuple(int firstNumber, int secondNumber) 
{



	//"ѕереработанный" алгоритм с использованием for и tuple
	TP_int X = { firstNumber,1,0 }, Y = { secondNumber,0,1 }, Temporary = { 0,0,0 };

	for (int i = 0, q = 0; get<0>(Y) != 0; i++) 
	{
		q = get<0>(X) / get<0>(Y);
		Temporary = { get<0>(X) % get<0>(Y),get<1>(X) - q * get<1>(Y),	get<2>(X) - q * get<2>(Y) };
		X = Y;
		Y = Temporary;
	}

	//ѕервоначальный алгоритм с использованием tuple и while
	/*int q = 0, i = 0;
	while (get<0>(Y) != 0) {
		cout << "»тераци€ є" << i << endl;
		cout << "X: ( " << get<0>(X) << ", " << get<1>(X) << ", " << get<2>(X) << " )" << endl;
		cout << "Y: ( " << get<0>(Y) << ", " << get<1>(Y) << ", " << get<2>(Y) << " )" << endl;
		q = get<0>(X) / get<0>(Y);
		cout << "q = x1 / y1 = " << get<0>(X) << " / " << get<0>(Y) << " = " << q << endl;
		Temporary = { get<0>(X) % get<0>(Y),get<1>(X) - q * get<1>(Y),	get<2>(X) - q * get<2>(Y) };
		cout << "Temporary: ( " << get<0>(X) << " % " << get<0>(Y) << " = " << get<0>(Temporary) << ", " << get<1>(X) << " - " << q << " * " << get<1>(Y) << " = " << get<1>(Temporary) << ", " << get<2>(X) << " - " << q << " * " << get<2>(Y) << " = " << get<2>(Temporary) << " )" << endl;
		X = Y;
		cout << "X = Y = (" << get<0>(X) << " " << get<1>(X) << " " << get<2>(X) << ")" << endl;
		Y = Temporary;
		cout << "Y = Temporary = (" << get<0>(Y) << " " << get<1>(Y) << " " << get<2>(Y) << ")" << endl << endl;
		i++;
	}*/
	cout << "X: ( " << get<0>(X) << ", " << get<1>(X) << ", " << get<2>(X) << " )" << endl;
	cout << "Y: ( " << get<0>(Y) << ", " << get<1>(Y) << ", " << get<2>(Y) << " )" << endl;
	//cout << "Temporary: ( " << get<0>(Temporary) << ", " << get<1>(Temporary) << ", " << get<2>(Temporary) << " )" << endl;
	cout << "d = " << get<0>(X) << ", u = " << get<1>(X) << ", v = " << get<2>(X) << endl;

	return X;
}
#endif // _GEA_tuple

