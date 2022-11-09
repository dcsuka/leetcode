#include <iostream>
#include <string>
#include <string_view>
#include <stack>
#include <chrono>

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

class StackSolution {
public:git 
    int calculate(string s) {
        stack<int> nums;
        stack<int> signs;
        long ret = 0, num = 0, sign = 1;
        for (char &c : s) {
            if (c >= '0' && c <= '9') num = num * 10 + c - '0';
            else if (c == '+' || c == '-') {
                ret = ret + sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                nums.emplace(ret); ret = 0;
                signs.emplace(sign), sign = 1;
                num = 0;
            }
            else if (c == ')') {
                ret = ret + sign * num;
                num = 0;
                ret = nums.top() + signs.top() * ret;
                nums.pop(); signs.pop();
            }
        }
        ret = ret + sign * num;
        return ret;
    }
};

int main () {
    MySolution sol;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; ++i) {
        int x = sol.calculate("5 - 0 + 4");
        x = sol.calculate("5 - (1 + 1)");
        x = sol.calculate("1 + 1");
        x = sol.calculate(" 2-1 + 2 ");
        x = sol.calculate("+157 - 58 ");
        x = sol.calculate("(1+(4+5+2)-3)+(6+8)");
        x = sol.calculate("(11-(43 +511-2 )-3)-(6+8)");
        x = sol.calculate("(7)-(0)+(4)");
        x = sol.calculate("1-(     -2)");        
    }
    auto end = chrono::high_resolution_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds> (end - start);
    cout << time.count() << endl;

    StackSolution ssol;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; ++i) {
        int x = sol.calculate("5 - 0 + 4");
        x = sol.calculate("5 - (1 + 1)");
        x = sol.calculate("1 + 1");
        x = sol.calculate(" 2-1 + 2 ");
        x = sol.calculate("+157 - 58 ");
        x = sol.calculate("(1+(4+5+2)-3)+(6+8)");
        x = sol.calculate("(11-(43 +511-2 )-3)-(6+8)");
        x = sol.calculate("(7)-(0)+(4)");
        x = sol.calculate("1-(     -2)");         
    }
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::microseconds> (end - start);   
    cout << time.count() << endl;

    return 0;
}