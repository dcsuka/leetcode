#include <iostream>
#include <vector>
#include <cassert>

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
    vector<vector<int>> permute(vector<int> &nums)
    {
        // All integers in nums are unique
        return vector<vector<int>>{{}};
    }
};

int main()
{
    return 0;
}