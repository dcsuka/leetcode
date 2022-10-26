class Solution
{
public:
    vector<int> dir{-1, 0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int down = mat.size(), right = down ? mat[0].size() : 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < down; ++i)
        {
            for (int j = 0; j < right; ++j)
            {
                if (!mat[i][j])
                    q.emplace(i, j);
                else
                    mat[i][j] = -1;
            }
        }

        while (q.size())
        {
            auto [r, c] = q.front();
            q.pop();
            for (int z = 0; z < 4; ++z)
            {
                int a = r + dir[z];
                int b = c + dir[z + 1];
                if (a < 0 || a >= down || b < 0 || b >= right || mat[a][b] != -1)
                    continue;
                mat[a][b] = mat[r][c] + 1;
                q.emplace(a, b);
            }
        }
        return mat;
    }
};