#include "User.h"

ostream& operator<<(ostream& ostr, const Vector_1D_int& Vec_1d) {
  ostr << "{ ";
  for (unsigned int i = 0; i < Vec_1d.size(); i++) ostr << Vec_1d[i] << " ";
  ostr << "}";

  return ostr;
}

ostream& operator<<(ostream& ostr, const Vector_1D_long_long& Vec_1d) {
  ostr << "{ ";
  for (unsigned int i = 0; i < Vec_1d.size(); i++) ostr << Vec_1d[i] << " ";
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

ostream& operator<<(ostream& ostr, const Vector_2D_long_long& Vec_2d) {
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

ostream& operator<<(ostream& ostr,
                    const Vector_1D_pair_long_long_int& Vec_pair) {
  ostr << "{ ";
  for (unsigned int i = 0; i < Vec_pair.size(); i++) {
    ostr << Vec_pair[i].first << ": " << Vec_pair[i].second << " ";
  }
  ostr << "}";

  return ostr;
}

void User::SetUser_Name(string _str) { User_Name = _str; }

void User::SetSender(bool _sender) { sender = _sender; }

int User::Get_Message_Size() { return message.size(); }

Vector_1D_long_long_int User::Get_Message() { return message; }

void User::InsertMessage() {
  char choice;
  bool stop = true;
  do {
    stop = true;
    cout << "Выберите тип вводимого сообщения:\n1. Число.\n2. Сообщение.\n\n: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
      case '1': {
        cin.ignore(32767, '\n');
        string _message;

        do {
          stop = true;
          cout << "Ввод числового сообщения:\n";
          cout << "Введите сообщение :\n\n: ";
          getline(cin, _message);
          cout << endl;

          for (auto i : _message)
            if ((i < '0') || (i > '9')) {
              cout << "Ошибка! были введены сторонние символы. Введите "
                      "сообщение снова.\n\n";
              stop = false;
              break;
            }
          if (stop) break;
        } while (true);

        SetMessage(stoi(_message));
        stop = true;
        break;
      }
      case '2': {
        cin.ignore(32767, '\n');
        string _message;

        cout << "Ввод строкового сообщения:\n";
        cout << "Введите сообщение :\n: ";
        getline(cin, _message);
        cout << endl;

        SetMessage(_message);
        stop = true;
        break;
      }
      default: {
        cout << "Вы неверно ввели номер варианта. Повторите ввод еще раз."
             << endl
             << endl;
        stop = false;
      }
    }
    if (stop) break;
  } while (true);
}

void User::SetMessage(unsigned long long int _message) {
  message.clear();

  message.push_back(_message);
}

void User::SetMessage(string _message) {
  message.clear();

  for (unsigned i = 0; i < _message.size(); i++) {
    message.push_back(_message[i]);
  }
}

void User::SetMessage(Vector_1D_long_long_int _message) {
  message.clear();
  message = _message;
}

string User::Message_ToString() {
  string _message;

  for (unsigned int i = 0; i < message.size(); i++) _message += message[i];

  return _message;
}

bool User::Prime(const int number) {
  auto sqrt_number = sqrt(number) + 1;

  for (unsigned int i = 2; i < sqrt_number; i++) {
    if (number % i == 0) return false;
  }

  return true;
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

void User::Generate_g_p(int& g, int& p) {
  do {
    p = PrimeRandom(1000000, 10000000);

    auto q = (p - 1) / 2;

    g = Random(2, p - 1);

    if ((g < p - 1) && (Mod_Exp(g, q, p) != 1) && (GCD(g, p) == 1)) break;
  } while (true);
}

long long User::GCD(long long firstNumber, long long secondNumber) {
  return secondNumber ? GCD(secondNumber, firstNumber % secondNumber)
                      : firstNumber;
}

long long User::Mod_Exp(long long base, long long power, long long divisor) {
  return (!power)
             ? (1 % divisor)
             : ((power % 2 == 1)
                    ? ((Mod_Exp(base, power - 1, divisor) * base) % divisor)
                    : Mod_Exp((base * base) % divisor, power / 2, divisor));
}

Vector_2D_int User::GEA(int firstNumber, int secondNumber) {
  Vector_2D_int Matrix = {
      {firstNumber, 1, 0},  // U
      {secondNumber, 0, 1}  // V
  };

  for (int i = 0, q = 0; Matrix[1][0] != 0; i++) {
    q = Matrix[0][0] / Matrix[1][0];
    Vector_1D_int Temp = {Matrix[0][0] % Matrix[1][0],
                          Matrix[0][1] - q * Matrix[1][1],
                          Matrix[0][2] - q * Matrix[1][2]};
    Matrix[0] = Matrix[1];
    Matrix[1] = Temp;
  }

  return Matrix;
}

long long User::Mod_Inverse(long long firstNumber, long long secondNumber) {
  auto u = make_pair(secondNumber, 0);
  auto v = make_pair(firstNumber, 1);

  for (; v.first > 0;) {
    auto q = u.first / v.first;
    auto t = make_pair(u.first % v.first, u.second - q * v.second);
    u = v;
    v = t;
  }

  if (u.second < 0) u.second += secondNumber;
  return u.second;
}

#ifdef _GEA_tuple
TP_int User::GEA_tuple(int firstNumber, int secondNumber) {
  TP_int X = {firstNumber, 1, 0}, Y = {secondNumber, 0, 1},
         Temporary = {0, 0, 0};

  for (int i = 0, q = 0; get<0>(Y) != 0; i++) {
    q = get<0>(X) / get<0>(Y);
    Temporary = {get<0>(X) % get<0>(Y), get<1>(X) - q * get<1>(Y),
                 get<2>(X) - q * get<2>(Y)};
    X = Y;
    Y = Temporary;
  }

  return X;
}
#endif  // _GEA_tuple
