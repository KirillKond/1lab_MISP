#pragma once
#include <string>
using namespace std;
class modAlphaCipher
{
private:
int key;
public:
modAlphaCipher()=delete;//запретим конструктор без параметров
modAlphaCipher(const int skey);//конструктор для установки ключа
string encrypt(string& open_text);//зашифрование
string decrypt(string& cipher_text);//расшифрование
};
