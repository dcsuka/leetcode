#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

template <typename T>
void print(const T &myT)
{
    for (auto x : myT)
        std::cout << x << " ";
    std::cout << std::endl;
}

bool wordBreak(string s, vector<string> &myvec)
{
    string_view sv{s};
    unordered_set<string_view> dict;
    for (const string_view &x : myvec)
        dict.emplace(x);
    if (dict.size() == 0)
        return false;
    vector<bool> dp(sv.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            cout << i << " " << j << endl;
            print(dp);
            if (dp[j])
            {
                if (dict.count(sv.substr(j, i - j)))
                {
                    dp[i] = true;
                    break; // next i
                }
            }
        }
    }

    return dp[s.size()];
}

int main()
{
    vector<string> veca{"leet", "code", "love"};
    cout << wordBreak(string("leetcode"), veca) << endl;
    return 0;
}