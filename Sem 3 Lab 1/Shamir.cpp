#include "Shamir.h"

Shamir::Shamir() 
{
    p = NULL;
    sender = NULL;
}

Shamir::Shamir(unsigned long long int _p, bool _sender) 
{
    p = _p;
    sender = _sender;
    if (sender)
    {
        InsertMessage();
        Generate_key();
    }
}

Shamir::Shamir(Shamir& first_user, Shamir& second_user) 
{
    sender = false;

    p = NULL;
    message.push_back(NULL);
    key.insert(make_pair(NULL, NULL));

    first_user.Encode(first_user.Get_Message());

    second_user.Encode(first_user.Get_Message());
    
    first_user.Decode(second_user.Get_Message());
    
    second_user.Decode(first_user.Get_Message());
 }



bool Shamir::check_for_equal_keys(unsigned long long int _key) 
{
    Vector_1D_long_long_int k;

    Get_map_key(k);

    for (unsigned int i = 0; i < k.size(); i++) 
    {
        if (_key == k[i]) return true;
    }

    return false;
}

bool Shamir::check_for_equal_values(unsigned long long int _value) 
{
    Vector_1D_long_long_int v;

    Get_map_value(v);

    for (unsigned int i = 0; i < v.size(); i++) 
    {
        if (_value == v[i]) return true;
    }

    return false;
}

void Shamir::Get_map_key(Vector_1D_long_long_int & _key)
{
    _key.clear();
    _key.reserve(key.size());

    for (map<unsigned long long int, unsigned long long int>::iterator i = key.begin(); i != key.end(); ++i)
    {
        _key.push_back(i->first);
    }
}

void Shamir::Get_map_value(Vector_1D_long_long_int& _value) 
{
    _value.clear();
    _value.reserve(key.size());

    for (map<unsigned long long int, unsigned long long int>::iterator i = key.begin(); i != key.end(); ++i)
    {
        _value.push_back(i->second);
    }
}

void Shamir::Generate_key() 
{
    for (unsigned int i = 0; i < message.size(); i++)
        do 
        {
            unsigned long long int c = 0;
            do 
            {
                c = Random(2, 1000);
            } while (GCD(c, p - 1) != 1);

            unsigned long long int d = Mod_Inverse(c, p - 1);
            if ((!check_for_equal_keys(c)) && (!check_for_equal_values(d))) 
            {
                key.insert(make_pair(c, d));
                break;
            }
        } while (true);
}

void Shamir::Encode(Vector_1D_long_long_int _message) 
{
    message.clear();
    message = _message;
    if (!sender) Generate_key();

    Vector_1D_long_long_int k;
    
    Get_map_key(k);

    for (unsigned int i = 0; i < message.size(); i++) 
    {
        message[i] = Mod_Exp(message[i], k[i], p);
    }
}

void Shamir::Decode(Vector_1D_long_long_int _message)
{
    message.clear();
    message = _message;

    Vector_1D_long_long_int v;

    Get_map_value(v);

    for (unsigned int i = 0; i < message.size(); i++) 
    {
        message[i] = Mod_Exp(message[i], v[i], p);
    }
}

void Shamir::PrintData() 
{
    Vector_1D_long_long_int k, v;

    Get_map_key(k);
    Get_map_value(v);

    cout << "Name: " << User_Name << endl;
    cout << "sender: " << sender << endl;
    cout << "p: " << p << endl;
    cout << "message array: " << message << endl;
    cout << "message = " << Message_ToString() << endl;
    cout << "key: { ";
    for (unsigned int i = 0; i < key.size(); i++)
        cout << k[i] << ": " << v[i] << " ";
    cout << "}" << endl << endl;

}

Shamir::~Shamir() 
{
    User_Name = "";
    p = NULL;
    key.clear();
    message.clear();
    sender = false;
}