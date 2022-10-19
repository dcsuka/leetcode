#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void swap(int &a, int &b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    std::vector<std::vector<int>> rotateRight(std::vector<std::vector<int>> &myVec)
    {
        const int rows = myVec.size(), cols = myVec[0].size();
        // A zero extra space alternative to:
        // std::reverse(myVec.begin(), myVec.end());

        for (int i = 0; i < rows / 2; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                swap(myVec[i][j], myVec[rows - i - 1][j]);
            }
        }

                for (int i = 1; i < rows; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                swap(myVec[i][j], myVec[j][i]);
            }
        }
        return myVec;
    }

    void printVec(std::vector<std::vector<int>> &myVec)
    {
        for (auto x : myVec)
        {
            for (auto y : x)
            {
                std::cout << y << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Solution a;

    std::vector<std::vector<int>> one = {std::vector<int>{1}};
    a.printVec(one);
    a.rotateRight(one);
    a.printVec(one);

    std::vector<std::vector<int>> two = {std::vector<int>{1, 2}, std::vector<int>{3, 4}};
    a.printVec(two);
    a.rotateRight(two);
    a.printVec(two);

    std::vector<std::vector<int>> three = {std::vector<int>{1, 2, 3}, std::vector<int>{4, 5, 6}, std::vector<int>{7, 8, 9}};
    a.printVec(three);
    a.rotateRight(three);
    a.printVec(three);

    std::vector<std::vector<int>> four = {std::vector<int>{1, 2, 3, 4}, std::vector<int>{5, 6, 7, 8}, std::vector<int>{1, 2, 3, 4}, std::vector<int>{5, 6, 7, 8}};
    a.printVec(four);
    a.rotateRight(four);
    a.printVec(four);
    return 0;
}