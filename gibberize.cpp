#include <iostream>
#include <string>
#include <unordered_map>
#include <codecvt> 

using namespace std;

//Leave first three vowels intact, only gibberize last four if possible

class Solution {
public:
    unordered_map<wchar_t, wchar_t> m {{'A', L'Á'},{'a', L'á'},{'E', L'É'},{'e', L'é'},{'I', L'Í'},{'i', L'í'},{'O', L'Ó'},{'o', L'ó'},{'U', L'Ú'},{'u', L'ú'}};
    void gibberize(wstring &s) {
        int i, vowelcount = 0, lim = s.size();
        for (i = 0; i < lim; ++i) {
            wchar_t &c = s[i];
            if (m.count(c)) ++vowelcount;
            if (vowelcount == 3) break;
        }
        vowelcount = 0;
        for (int j = lim - 1; j > i; --j) {
            wchar_t &c = s[j];
            if (m.count(c)) {
                c = m[c];
                ++vowelcount;
            }
            if (vowelcount == 4) break;
        }
    }
};

int main() {
    Solution sol;
    wstring a = L"abdsfsisdfdsesfU";
    sol.gibberize(a);
    wcout << a << endl;

    wstring ab = L"abdsfsisdfdsesfUba";
    sol.gibberize(ab);
    wcout << ab << endl;

    wstring abc = L"abdsfsisdfdsesfUae";
    sol.gibberize(abc);
    wcout << abc << endl;

    wstring abcd = L"abdsfsisdfdsesfUsfsadfdfeiasfua";
    sol.gibberize(abcd);
    wcout << abcd << endl;
    return 0;
}