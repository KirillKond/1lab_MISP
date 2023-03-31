#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <cstdlib>
#include <locale>
using namespace std;
class modAlphaCipher
{
private:
    std::string numAlpha = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    wstring wnumAlpha;
    std::map <wchar_t,int> alphaNum;//ассоциативный массив "номер по символу"
    std::vector <int> key;//ключ
    std::vector <int> convert(const std::wstring& s);//преобразование строка-вектор
    std::wstring convert(const std::vector<int>& v);//преобразование вектор-строка
public:
    modAlphaCipher()=delete;//запретим конструктор без параметров
    modAlphaCipher(const std::wstring& skey);//конструктор для установки ключа
    std::wstring encrypt(const std::wstring& open_text);
    std::wstring decrypt(const std::wstring& cipher_text);
};
