#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include <cmath>

using namespace std;

int add(const int &a, const int &b) { return a + b; }
int mult(const int &a, const int &b) { return a * b; }
int divide(const int &a, const int &b) { return a / b; }
int sub(const int &a, const int &b) { return a - b; }

int main()
{
    unordered_map<string, function<int(const int &, const int &)>> mymap{{"+", std::plus()}, {"*", mult}, {"/", divide}, {"-", sub}};
    auto func = mymap.find("-");
    cout << func->second(5, 4) << endl;
    cout << min(5, 4, 3) << endl;
    return 0;
}