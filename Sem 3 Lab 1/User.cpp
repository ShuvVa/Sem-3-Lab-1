#include "User.h"

ostream& operator<<(ostream& ostr, const Vector_1D_int& Vec_1d) {
	
	ostr << "{ ";
	for (unsigned int i = 0; i < Vec_1d.size(); i++)
		ostr << Vec_1d[i] << " ";
	ostr << "}";

	return ostr;
}

ostream& operator<<(ostream& ostr, const Vector_2D_int& Vec_2d) {
	
	
	for (unsigned int i = 0; i < Vec_2d.size(); i++) {
		ostr << "{ ";
		for (unsigned int j = 0; j < Vec_2d[i].size(); j++)
			ostr << Vec_2d[i][j] << " ";
		ostr << "}";
		if (!(i == Vec_2d.size() - 1)) ostr << ",";
		
		ostr << "\n";

	}
	
	
	return ostr;
}

bool User::Prime(const int number) {
	//	¬ случае, если number больше 4, то используем свойство простых чисел, больше или равных 5 - при возведении во вторую степень и вз€тии отстатка от делени€ на 24, остаток всегда будет 1. ≈сли number меньше или равно 4
	if (number > 4) {
		return ((number * number) % 24 == 1);
	}
	else {
		vector <int> Numbers;
		//	»нициализаци€ элементов вектора посредством помещени€ в него массива чисел от 2 до number включительно
		for (int i = 2; i <= number; i++) {
			Numbers.push_back(i);
		}
		//	ѕроверка на то, €вл€етс€ ли число простым - если нет, оно замен€етс€ нулем
		for (int i = 0; i < int(Numbers.size()); i++) {
			int j = 2;
			while (j <= Numbers[i]) {
				if ((Numbers[i] % j == 0) && (Numbers[i] != j)) {
					Numbers[i] = 0;
				}
				j++;
			}
		}
		//	”борка нулей из массива
		int i = 0;
		while (i<int(Numbers.size())) {
			if (Numbers[i] == 0) {
				Numbers.erase(Numbers.begin() + i);
				i = 0;
				continue;
			}
			i++;
		}
		//	≈сли последний элемент массива равно number, возращаетс€ значение TRUE, в ином случае - FALSE
		return (number == Numbers[Numbers.size() - 1]);
	}
}

int User::Random(int begining, int ending) {
	return (begining + rand() % (ending - begining));
}

int User::PrimeRandom(int begining, int ending) {	
	int number = 0;

	do {
		number = begining + rand() % (ending - begining);
	} while (!(Prime(number)));

	return number;
}

Vector_1D_int User::GEA(int firstNumber, int secondNumber) {
	Vector_2D_int Matrix = {
		{firstNumber,1,0},
		{secondNumber,0,1},
		{0,0,0}
	};
	
	
	for (int i = 0, q = 0; Matrix[1][0]!=0;i++) {
		q = Matrix[0][0] / Matrix[1][0];
		Matrix[2] = { Matrix[0][0] % Matrix[1][0] , Matrix[0][1] - q * Matrix[1][1], Matrix[0][2] - q * Matrix[1][2] };
		Matrix[0] = Matrix[1];
		Matrix[1] = Matrix[2];
	}

	//cout << Matrix[0] << endl;
	//cout << Matrix[1];
	cout << Matrix;

	return Matrix[0];
}
#ifdef _GEA_tuple
TP User::GEA_tuple(int firstNumber, int secondNumber) {



	//"ѕереработанный" алгоритм с использованием for и tuple
	tuple <int, int, int> X = { firstNumber,1,0 }, Y = { secondNumber,0,1 }, Temporary = { 0,0,0 };

	for (int i = 0, q = 0; get<0>(Y) != 0; i++) {
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

