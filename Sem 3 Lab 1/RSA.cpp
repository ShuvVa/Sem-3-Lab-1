#include "RSA.h"

RSA::RSA()
{
	sender = false;
	p.push_back(NULL);
	q.push_back(NULL);
	fi.push_back(NULL);
	c.push_back(NULL);
	d.push_back(NULL);
	message.push_back(NULL);
}

RSA::RSA(bool _sender)
{
	sender = _sender;
	if (sender)
	{
		InsertMessage();
	}
}

RSA::RSA(RSA& first_user, RSA& second_user)
{
	second_user.Generate_p(first_user.Get_Message_Size());
	first_user.Encrypt(second_user.Get_d(), second_user.Get_n());
	second_user.SetMessage(first_user.Get_Message());
	second_user.Decrypt();
}


void RSA::Generate_p()
{
	p.clear();
	for (unsigned i = 0; i < message.size(); i++)
		p.push_back(PrimeRandom(10000, 100000));
	Generate_q();
}

void RSA::Generate_p(int _message_size)
{
	p.clear();
	for (unsigned i = 0; i < _message_size; i++)
		p.push_back(PrimeRandom(10000, 100000));
	Generate_q();
}

void RSA::Generate_q()
{
	q.clear();
	for (unsigned i = 0; i < p.size(); i++)
		q.push_back(PrimeRandom(10000, 100000));

	Calc_n();
	Calc_fi();
	Generate_d();
	Calc_c();
}

void RSA::Generate_d()
{
	d.clear();
	int _d;
	for (unsigned int i = 0; i < p.size(); i++)
		do
		{
			_d = Random(100000, fi[i]);
			if ((_d < fi[i]) && (GCD(_d, fi[i]) == 1))
			{
				d.push_back(_d);
				break;
			}
		} while (true);

}

Vector_1D_long_long_int RSA::Get_d()
{
	return d;
}

Vector_1D_long_long_int RSA::Get_n()
{
	return n;
}

void RSA::Calc_n()
{
	n.clear();
	for (unsigned int i = 0; i < p.size(); i++)
		n.push_back(p[i] * q[i]);
}

void RSA::Calc_fi()
{
	fi.clear();
	for (unsigned int i = 0; i < p.size(); i++)
		fi.push_back((p[i] - 1) * (q[i] - 1));
}

void RSA::Calc_c()
{
	c.clear();
	for (unsigned int i = 0; i < p.size(); i++)
		c.push_back(Mod_Inverse(d[i], fi[i]));
}

void RSA::Encrypt(Vector_1D_long_long_int _d, Vector_1D_long_long_int _n)
{
	for (unsigned int i = 0; i < message.size(); i++)
		message[i] = Mod_Exp(message[i], _d[i], _n[i]);
}

void RSA::Decrypt()
{
	for (unsigned int i = 0; i < message.size(); i++)
		message[i] = Mod_Exp(message[i], c[i], n[i]);
}

void RSA::PrintData()
{
	cout << "Name: " << User_Name << endl;
	cout << "sender: " << sender << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "n: " << n << endl;
	cout << "fi: " << fi << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "message: " << message << endl;
	cout << "converted message: " << Message_ToString() << endl << endl;
}

RSA::~RSA()
{
	p.clear();
	q.clear();
	fi.clear();
	c.clear();
	d.clear();
	message.clear();
}