#include <iostream>
#include <string>
#include <string_view>
#include <functional>

using namespace std;

//A basic calculator that supports addition and subtraction, with or without parentheses.

class MySolution {
public:
    pair<int, int> calculateSection(const string_view &sv, bool ReturnOnCloseParentheses) {
        int ret = 0, newNum = 0, i;
        char func = '+';
        int lim = sv.size();
        for (i = 0; i < lim; ++i) {
            char c = sv[i];
            if (c == ')' && ReturnOnCloseParentheses) break;
            if (c == '(') {
                int newStart = i + 1;
                auto x = calculateSection(sv.substr(newStart), true);
                newNum = x.first;
                i += x.second + 1;
                c = ' ';
            }
            if (c == ' ' && !newNum) continue;
            if (c == '-' || c == '+' || c == ' ') {
                if (func == '+') ret += newNum;
                else {
                    ret -= newNum;
                    func = '+';
                }
                newNum = 0;
                if (c == '-' || c == '+') func = c;
            }
            else if (c >= '0' && c <= '9') {
                newNum *= 10;
                newNum += c - '0';
            }
        }
        if (newNum) (func == '+') ? ret += newNum : ret -= newNum;
        return pair<int, int> (ret, i++);
    }
    int calculate(string s) {
        string_view sv(s);
        return calculateSection(sv, false).first;
    }
};

int main () {
    MySolution sol;
    cout << sol.calculate("5 - 0 + 4") << " == 9" << endl;
    cout << sol.calculate("5 - (1 + 1)") << " == 3" << endl;
    cout << sol.calculate("1 + 1") << " == 2" << endl;
    cout << sol.calculate(" 2-1 + 2 ") << " == 3" << endl;
    cout << sol.calculate("+157 - 58 ") << " == 99" << endl;
    cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << " == 23" << endl;
    cout << sol.calculate("(11-(43 +511-2 )-3)-(6+8)") << " == -558" << endl;
    cout << sol.calculate("(7)-(0)+(4)") << " == 11" << endl;
    cout << sol.calculate("1-(     -2)") << " == 3" << endl;
    return 0;
}