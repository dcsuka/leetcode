#include <iostream>
#include <string>
#include <vector>
#include <string_view>

using namespace std;

namespace BruteForce
{
    class Solution
    {
    public:
        string longestPalindrome(string s);
        bool isPalindrome(const string_view &s);
    };

    string Solution::longestPalindrome(string s)
    {
        auto n = s.size();
        decltype(n) maxlen = 0u;
        string_view sv(s);
        string ret;
        for (decltype(n) i = 0; i <= n; ++i)
        {
            for (decltype(n) j = i - 1; j != -1; --j)
            {
                auto x = i - j;
                if (x > maxlen && Solution::isPalindrome(sv.substr(j, x)))
                {
                    maxlen = x;
                    ret = s.substr(j, x);
                }
            }
        }
        return ret;
    }

    bool Solution::isPalindrome(const string_view &s)
    {
        auto right = s.size() - 1;
        decltype(right) left = 0u;
        while (left < right)
        {
            if (s.at(left) != s.at(right))
                return false;
            ++left;
            --right;
        }
        return true;
    }
}

int main()
{
    return 0;
}