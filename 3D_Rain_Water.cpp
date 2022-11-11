#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print(const std::vector<std::vector<T>> &myT)
{
    for (auto i : myT)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution {
public:
    int DIR[5] = {-1, 0, 1, 0, -1};
    int m, n, solidsum, maxheight, ret;
    int trapRainWater(vector<vector<int>>& heightMap) {
        m = heightMap.size(), n = heightMap[0].size(), solidsum = 0, maxheight = 0, ret = 0;
        if (m <= 1 || n <= 1) return 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                solidsum += heightMap[i][j];
                maxheight = max(maxheight, heightMap[i][j]);
            }
        }

        ret = m * n * maxheight - solidsum;
        vector<vector<int>> shaved (m, vector<int>(n, 0));

        //left, right, get corners too
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j += n - 1) {
                if (i == 0 || i == m - 1 || (heightMap[i][j] <= heightMap[i + 1][j]))
                    dfs(i, j, heightMap[i][j] + 1, heightMap, shaved);
            }
        }

        for (int i = 0; i < m; i += m - 1) {
            for (int j = 1; j < n - 1; ++j) {
                if (j == 0 || j == n - 1 || (heightMap[i][j] <= heightMap[i][j + 1]))
                    dfs(i, j, heightMap[i][j] + 1, heightMap, shaved);
            }
        }         

        return ret;
    }

    void dfs(int i, int j, int level,  vector<vector<int>>& board, vector<vector<int>>& shaved) {
        if (i < 0 || i >= m || j < 0 || j == n || board[i][j] == INT_MIN || board[i][j] + shaved[i][j] >= maxheight) return;
        level = max(level, board[i][j] + 1);
        if (level > maxheight) return;
        ret -= max(0, maxheight - level + 1 - shaved[i][j]);
        shaved[i][j] = max(shaved[i][j], maxheight - level + 1);
        int val = board[i][j];
        board[i][j] = INT_MIN;
        for (int z = 0; z < 4; ++z) {
            dfs(i + DIR[z], j + DIR[z + 1], level, board, shaved);
        }
        board[i][j] = val;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v1 {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout << sol.trapRainWater(v1) << " == 4" << endl;
    vector<vector<int>> v2 {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    cout << sol.trapRainWater(v2) << " == 10" << endl;
    vector<vector<int>> v3 {{3,1,3,3,3},{3,1,1,1,3},{3,1,1,1,3},{3,1,1,1,3},{3,3,3,3,3}};
    cout << sol.trapRainWater(v3) << " == 0" << endl;
    vector<vector<int>> v4 {{1}};
    cout << sol.trapRainWater(v4) << " == 0" << endl;
    vector<vector<int>> v5 {{18,13,13,17,12,11},{17,2,6,10,5,10},{11,10,2,8,8,2},{12,6,10,8,8,7},{18,4,7,6,7,4},{20,5,9,2,3,10}};
    cout << sol.trapRainWater(v5) << " == 18" << endl;
    return 0;
}