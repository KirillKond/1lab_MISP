#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <codecvt>
#include <cstdlib>
#include <locale>
using namespace std;
bool isValid(const wstring& s)
{
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    for(auto c:s)
        if (!isalpha(c,loc) || !isupper(c,loc))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring wres;
    string res;
    string key;
    string text;
    unsigned op;
    cout<<"Cipher ready. Input key: ";
    cin>>key;
    wstring wkey = codec.from_bytes(key);
    if (!isValid(wkey)) {
        cerr<<"key not valid\n";
        return 1;
    }
    cout<<"Key loaded\n";
    modAlphaCipher cipher(wkey);
    do {
        cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
            cin>>op;
            if (op > 2) {
        cout<<"Illegal operation\n";
    } else if (op > 0) {
        cout<<"Cipher ready. Input text: ";
        cin>>text;
        wstring wtext = codec.from_bytes(text);
            if (isValid(wtext)) {
                if (op==1) {
                    wres =
                        cipher.encrypt(wtext);
                    res = codec.to_bytes(wres);
                    cout<<"Encrypted text: "<<res<<endl;
                } else {
                    wres =
                        cipher.decrypt(wtext);
                    res = codec.to_bytes(wres);
                    cout<<"Decrypted text: "<<res<<endl;
                }
            } else {
                cout<<"Operation aborted: invalid text\n";
            }
        }
    } while (op!=0);
    return 0;
}
