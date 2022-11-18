#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <chrono>

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

class NewSolution
{
public:
    vector<string> letterCombinations(string digits) {
        int numdigits = digits.size();
        vector<string> ret, letters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (numdigits == 0) return ret;
        string initial = letters[digits[0] - '2'];
        ret.reserve(initial.size());
        for (char &c : initial) ret.emplace_back(1, c);
        for (int a = 1; a < numdigits; ++a) {
            string newDigits = letters[digits[a] - '2'];
            int oldSize = ret.size(), newSize = newDigits.size(), retSize = oldSize * newSize;
            ret.resize(retSize);
            for (int i = retSize - 1; i != -1; --i) ret[i] = ret[i % oldSize] + newDigits[i / oldSize];
        }
        return ret;
    }
};

class CopySolution
{
public:
    vector<string> letterCombinations(string digits) {
        int numdigits = digits.size();
        vector<string> ret, letters{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (numdigits == 0) return ret;
        string initial = letters[digits[0] - '2'];
        ret.reserve(initial.size());
        for (char &c : initial) ret.emplace_back(1, c);
        for (int a = 1; a < numdigits; ++a) {
            string newDigits = letters[digits[a] - '2'];
            int oldsize = ret.size(), addsize = newDigits.size(), bigsize = oldsize * addsize;
            ret.reserve(bigsize);
            for (int i = 1; i < addsize; ++i) copy_n(ret.begin(), oldsize, back_inserter(ret));
            for (int j = 0; j < bigsize; ++j) ret[j].push_back(newDigits[j / oldsize]);
        }
        return ret;
    }
};

template <typename T>
void timeit(T &obj) {
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        obj.letterCombinations("294");
        obj.letterCombinations("39");
        obj.letterCombinations("6");
        obj.letterCombinations("");
    }
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl << endl;
}

int main()
{
    Solution a;
    print(a.letterCombinations("294"));
    print(a.letterCombinations("39"));
    print(a.letterCombinations("6"));
    print(a.letterCombinations(""));
    timeit(a);

    NewSolution ab;
    print(ab.letterCombinations("294"));
    print(ab.letterCombinations("39"));
    print(ab.letterCombinations("6"));
    print(ab.letterCombinations(""));
    timeit(ab);

    CopySolution abc;
    print(abc.letterCombinations("294"));
    print(abc.letterCombinations("39"));
    print(abc.letterCombinations("6"));
    print(abc.letterCombinations(""));
    timeit(abc);

    return 0;
}