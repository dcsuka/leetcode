#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

template <typename T>
void print(const std::vector<std::vector<T>> &myT)
{
    for (auto i : myT)
    {
        for (auto j : i)
        {
            string pad = (j < 10) ? "  " : (j < 100) ? " "
                                                     : "";
            std::cout << j << pad << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution
{
public:
    vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ret(n, vector<int>(n));
        int verticalLimit = n - 1, horizontalLimit = n, i = 0, j = -1, mode = 0, count = 1;
        int *curLimit = &horizontalLimit;
        while (*curLimit > 0)
        {
            auto directions = dir[mode];
            for (int z = 0; z < *curLimit; ++z)
            {
                i += directions.first;
                j += directions.second;
                ret[i][j] = count++;
            }
            mode = (mode + 1) % 4;
            --(*curLimit);
            curLimit = (curLimit == &horizontalLimit) ? &verticalLimit : &horizontalLimit;
        }
        return ret;
    }
};

int main()
{
    Solution a;
    print(a.generateMatrix(1));
    print(a.generateMatrix(2));
    print(a.generateMatrix(3));
    print(a.generateMatrix(4));
    print(a.generateMatrix(5));
    print(a.generateMatrix(9));
    print(a.generateMatrix(31));
    return 0;
}