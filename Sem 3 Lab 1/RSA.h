#pragma once
#include "User.h"
class RSA : public User
{
private:
	//long long int p, q, n, fi, c, d,m;

	Vector_1D_long_long_int p, q, n, fi, c, d, message;
	bool sender;
public:
	RSA();

	RSA(bool _sender = false);

	RSA(RSA& first_user, RSA& second_user);



	void Generate_p();

	void Generate_p(int _message_size);

	void Generate_q();

	void Generate_d();

	Vector_1D_long_long_int Get_d();

	Vector_1D_long_long_int GetMessage();

	int Get_Message_Size();

	Vector_1D_long_long_int Get_n();

	void Calc_n();

	void Calc_fi();

	void Calc_c();

	void InsertMessage();

	void SetMessage(int _message);

	void SetMessage(string _message);

	void SetMessage(Vector_1D_long_long_int _message);

	void Encrypt(Vector_1D_long_long_int _d, Vector_1D_long_long_int _n);

	void Decrypt();

	void PrintData();

	~RSA();
};

