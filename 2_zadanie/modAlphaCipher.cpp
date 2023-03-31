#include <iostream>
#include <string>
#include "modAlphaCipher.h"
using namespace std;
modAlphaCipher::modAlphaCipher(const int skey)
{
    key = skey;
}
string modAlphaCipher::encrypt(string& open_text)
{
    int t_key = key;
    while (open_text.size() % key != 0) {
        {
            open_text.push_back('*');
        }
        cout<<open_text<<endl;
    }
    string work = "";
    for (int i=0; i<key; i++) {
        for (unsigned long int j=0; j<(open_text.size() /
                                       key); j++) {
            work.push_back(open_text[t_key-1]);
            t_key +=key;
        }
        t_key = key-i-1;
    }
    return work;
}
string modAlphaCipher::decrypt(string& cipher_text)
{
    int t_key = cipher_text.size() / key;
    string work = "";
    for (unsigned long int i=0; i<(cipher_text.size() / key); i++) {
        for (int j=0; j<key; j++) {
            work.push_back(cipher_text[cipher_text.size() - t_key]);
            t_key += cipher_text.size() / key;
        }
        t_key = cipher_text.size() / key-i-1;
    }
    return work;
}
