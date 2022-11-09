#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

template <typename T>
void print (const T &myT) {
    for (auto x : myT) std::cout << x.first << " " << x.second << endl;
    std::cout << std::endl;
}

class Solution {
public:
    unordered_map<char, function<int(const int &, const int &)>> m = {{'+', plus()}, {'-', minus()}, {'*', multiplies()}, {'/', divides()}};
    int calculate(string s) {
        vector<pair<int, char>> vec;
        vec.emplace_back(0, '+');
        int num = 0, ret = 0;
        for (char &c : s) {
            auto tp = vec.back();
            if (c >= '0' && c <= '9') num = num * 10 + c - '0';
            else if (c != ' ') {
                if (tp.second == '*' || tp.second == '/') {
                    vec.back() = pair<int, char> {m[tp.second](tp.first, num), c};
                }
                else vec.emplace_back(num, c);
                num = 0;
            }
        }
        auto tp = vec.back();
        if (tp.second == '*' || tp.second == '/') {
            vec.back() = pair<int, char> {m[tp.second](tp.first, num), '+'};
        }
        else vec.emplace_back(num, '+');        
        print(vec);
        int lim = vec.size();
        char func = '+';
        for (int i = 1; i < lim; ++i) {
            ret = m[func](ret, vec[i].first);
            func = vec[i].second;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.calculate("3-2*2*3") << " == 9" << endl;
    cout << sol.calculate("3+2*2") << " == 7" << endl;
    cout << sol.calculate(" 3/2 ") << " == 1" << endl;
    cout << sol.calculate(" 3+5 / 2 ") << " == 5" << endl;
    cout << sol.calculate(" 3 - 0") << " == 3" << endl;
    return 0;
}