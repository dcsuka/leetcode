#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    const int maxOver10 = INT_MAX / 10;
    const int maxMod10 = INT_MAX % 10;
    const int minOver10 = -(INT_MIN / 10);

    int myAtoi(string s)
    {
        int ret = 0, i = 0, len = s.size(), sign = 1;
        while (s[i] == ' ' && i < len)
            ++i;
        if (s[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else if (s[i] == '+')
            ++i;
        while (i < len)
        {
            char x = s[i];
            if (x < '0' || x > '9')
                break;
            int digit = x - '0';
            if (sign == 1 && (ret > maxOver10 || (ret == maxOver10 && digit > maxMod10)))
                return INT_MAX;
            if (sign == -1 && (ret > minOver10 || (ret == minOver10 && digit > maxMod10))) // maxMod10 to prevent overflow on "-2147483648"
                return INT_MIN;
            ret = ret * 10 + digit;
            ++i;
        }
        return ret * sign;
    }
};

int main()
{
    Solution a;
    cout << a.myAtoi("42") << endl;
    cout << a.myAtoi("    -42") << endl;
    cout << a.myAtoi("4193.84 with words") << endl;
    cout << a.myAtoi("2147483647") << endl;
    cout << a.myAtoi("2147483648") << endl;
    cout << a.myAtoi("2147483700") << endl;
    cout << a.myAtoi("-2147483648") << endl;
    cout << a.myAtoi("-2147483649") << endl;
    return 0;
}