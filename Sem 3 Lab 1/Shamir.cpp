#include "Shamir.h"

Shamir::Shamir() {
    p = NULL;
    sender = NULL;
}

Shamir::Shamir(unsigned long long int _p, bool _sender) {
    p = _p;
    sender = _sender;
    if (sender)
    {
        IncertMessage();
        Generate_key();
    }
}

Shamir::Shamir(bool _sender, bool test) {
    sender = _sender;
    p = 23;
    unsigned long long int c = 0, d = 0;
    if (sender) {
        c = 7;
        //int d = Mod_Inverse(c, p - 1);
        d = 19;
        message.push_back(10);
    }
    else {
        c = 5;
        //int d = Mod_Inverse(c, p - 1);
        d = 9;
    }

    key.insert(make_pair(c, d));
}

Shamir::Shamir(Shamir& first_user, Shamir& second_user) {
    p = NULL;
    message.push_back(NULL);
    sender = false;
    key.insert(make_pair(NULL, NULL));

    //cout << "Step 1:" << endl;
    //first_user.PrintData();
    ////second_user.PrintData();
    first_user.Encode(first_user.GetMessage());

    //cout << "Step 2:" << endl;
    //first_user.PrintData();
    ////second_user.PrintData();
    second_user.Encode(first_user.GetMessage());
    //
    //cout << "Step 3:" << endl;
    ////first_user.PrintData();
    //second_user.PrintData();
    first_user.Decode(second_user.GetMessage());
    //
    //cout << "Step 4:" << endl;
    //first_user.PrintData();
    ////second_user.PrintData();
    second_user.Decode(first_user.GetMessage());
    //
    //cout << "Step 5:" << endl;
    ////first_user.PrintData();
    //second_user.PrintData();
}

bool Shamir::check_for_equal_keys(unsigned long long int _key) {
    Vector_1D_int k;
    k.reserve(key.size());

    for (map<unsigned long long int, unsigned long long int>::iterator i = key.begin(); i != key.end(); ++i)
    {
        k.push_back(i->first);
    }

    for (unsigned int i = 0; i < k.size(); i++) {
        if (_key == k[i]) return true;
    }

    return false;
}

bool Shamir::check_for_equal_values(unsigned long long int _value) {
    Vector_1D_int v;
    v.reserve(key.size());

    for (map<unsigned long long int, unsigned long long int>::iterator i = key.begin(); i != key.end(); ++i)
    {
        v.push_back(i->second);
    }

    for (unsigned int i = 0; i < v.size(); i++) {
        if (_value == v[i]) return true;
    }

    return false;
}

void Shamir::Generate_key() {
    for (unsigned int i = 0; i < message.size(); i++)
        do {
            unsigned long long int c = 0;
            do {
                c = Random(2, 1000);
            } while (GCD(c, p - 1) != 1);

            unsigned long long int d = Mod_Inverse(c, p - 1);
            if ((!check_for_equal_keys(c)) && (!check_for_equal_values(d))) {
                key.insert(make_pair(c, d));
                break;
            }
        } while (true);
}

void Shamir::IncertMessage() {
    unsigned long long int choice, message_int;
    string message_string;
    cout << "Введите тип сообщения:\n1. Число.\n2. Строка.\n: ";
    cin >> choice;
    switch (choice) {
    case 1: {
        cout << "Введите сообщение: \n: ";
        cin >> message_int;
        SetMessage(message_int);
        break;
    }
    case 2: {
        cin.ignore(32767, '\n');
        cout << "Введите сообщение: \n: ";
        getline(cin, message_string);
        SetMessage(message_string);
        break;
    }
    }
}

Vector_1D_int Shamir::GetMessage() {
    return message;
}

void Shamir::SetSender(bool _sender) {
    sender = _sender;
}

void Shamir::SetMessage(string _message) {
    message.clear();
    for (unsigned int i = 0; i < _message.size(); i++) {
        message.push_back(_message[i]);
    }
}

void Shamir::SetMessage(unsigned long long int _message) {
    message.clear();
    message.push_back(_message);
}

void Shamir::Encode(Vector_1D_int _message) {
    message.clear();
    message = _message;
    if (!sender) Generate_key();
    Vector_1D_int k;
    k.reserve(key.size());

    for (map<unsigned long long int, unsigned long long int>::iterator i = key.begin(); i != key.end(); ++i)
    {
        k.push_back(i->first);
    }

    for (unsigned int i = 0; i < message.size(); i++) {
        message[i] = Mod_Exp(message[i], k[i], p);
    }
}

void Shamir::Decode(Vector_1D_int _message) {
    message.clear();
    message = _message;

    Vector_1D_int v;
    v.reserve(key.size());

    for (map<unsigned long long int, unsigned long long int>::iterator i = key.begin(); i != key.end(); ++i)
    {
        v.push_back(i->second);
    }

    for (unsigned int i = 0; i < message.size(); i++) {
        message[i] = Mod_Exp(message[i], v[i], p);
    }
}

void Shamir::PrintData() {
    Vector_1D_int k, v;
    k.reserve(key.size());
    v.reserve(key.size());

    for (map<unsigned long long int, unsigned long long int>::iterator i = key.begin(); i != key.end(); ++i)
    {
        k.push_back(i->first);
        v.push_back(i->second);
    }

    cout << "Name: " << User_Name << endl;
    cout << "sender: " << sender << endl;
    cout << "p: " << p << endl;
    cout << "message array: " << message << endl;

    string _message;
    for (unsigned int i = 0; i < message.size(); i++) _message += char(message[i]);
    cout << "message = " << _message << endl;

    cout << "key: {";
    for (unsigned int i = 0; i < key.size(); i++)
        cout << k[i] << ": " << v[i] << " ";
    cout << "}" << endl << endl;

}

Shamir::~Shamir() {
    User_Name = "";
    p = NULL;
    key.clear();
    message.clear();
    sender = false;
}