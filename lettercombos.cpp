#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void print(const T &myT)
{
    for (auto x : myT)
        std::cout << x << " ";
    std::cout << std::endl;
}

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        int numdigits = digits.size();
        vector<string> ret, letters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ret.reserve(numdigits);
        if (!numdigits)
            return ret;
        for (char c : letters[digits[0] - '2'])
            ret.push_back(string(1, c));
        for (int i = 1; i < numdigits; ++i)
        {
            string newlets = letters[digits[i] - '2'];
            int oldsize = ret.size(), newletsize = newlets.size(), newsize = oldsize * newletsize;
            ret.reserve(newsize);
            for (int j = 0; j < newletsize - 1; ++j)
            {
                for (int f = 0; f < oldsize; ++f)
                {
                    ret.emplace_back(ret[f]);
                }
            }
            for (int y = 0; y < newsize; ++y)
            {
                ret[y] += newlets[y / oldsize];
            }
        }
        return ret;
    }
};

int main()
{
    Solution a;
    print(a.letterCombinations("294"));
    print(a.letterCombinations("39"));
    print(a.letterCombinations("6"));
    print(a.letterCombinations(""));
    return 0;
}