#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <cstdlib>
#include <locale>
#include "modAlphaCipher.h"
using namespace std;
modAlphaCipher::modAlphaCipher(const std::wstring& skey)
{
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    wnumAlpha = codec.from_bytes(numAlpha);
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[wnumAlpha[i]]=i;
    }
    key = convert(skey);
}
std::wstring modAlphaCipher::encrypt(const std::wstring&
                                     open_text)
{
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    std::vector<int> work = convert(open_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) %
                  alphaNum.size();
    }
    return convert(work);
}
std::wstring modAlphaCipher::decrypt(const std::wstring&
                                     cipher_text)
{
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    std::vector<int> work = convert(cipher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i %
                   key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline std::vector<int> modAlphaCipher::convert(const
        std::wstring& s)
{
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    std::vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline std::wstring modAlphaCipher::convert(const
        std::vector<int>& v)
{
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    std::wstring result;
    for(auto i:v) {
        result.push_back(wnumAlpha[i]);
    }
    return result;
}
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
