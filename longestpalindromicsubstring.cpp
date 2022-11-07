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

using sst = string::size_type;

namespace TwoPointer
{
    class Solution
    {
    public:
        string longestPalindrome(string s);
    };

    string Solution::longestPalindrome(string s) {
        sst n = s.size();
        if (n == 0) return "";
        string ret(1, s.at(0));
        for (sst i = 0; i < n; ++i) {
            sst left = i, right = i;
            while (left > 0 && s.at(left - 1) == s.at(left)) --left;
            while (right < n - 1 && s.at(right + 1) == s.at(right)) ++right;
            while (left > 0 && right < n - 1 && s.at(left - 1) == s.at(right + 1)) --left, ++right;
            if (right - left + 1 > ret.size()) ret = s.substr(left, right - left + 1);
        }
        return ret;
    }
}
int main()
{
    BruteForce::Solution bf;
    cout << bf.longestPalindrome("sdfddbababsdf") << endl;
    TwoPointer::Solution tp;
    cout << tp.longestPalindrome("sdfddbababsdf") << endl;
    return 0;
}