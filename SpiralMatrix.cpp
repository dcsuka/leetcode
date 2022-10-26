#include <iostream>
#include <vector>

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
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size() - 1, n = matrix[0].size(), i = 0, j = -1, mode = 0;
        int *curDist = &n;
        vector<int> ret;
        ret.reserve(m * n);
        while (*curDist > 0)
        {
            cout << "m: " << m << ", n: " << n << endl;
            pair<int, int> directions = dir[mode];
            cout << "directions: " << directions.first << directions.second << endl;
            for (int z = 0; z < *curDist; ++z)
            {
                i += directions.first;
                j += directions.second;
                std::cout << i << j << endl;
                ret.emplace_back(matrix[i][j]);
            }
            mode = (mode + 1) % 4;
            *curDist = *curDist - 1;
            curDist = (curDist == &n) ? &m : &n;
            print(ret);
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> mat1{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Solution s;
    auto x = s.spiralOrder(mat1);
    print(x);
    return 0;
}