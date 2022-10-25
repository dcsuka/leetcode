#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> getSpiral(std::vector<std::vector<int>> &matrix)
    {
        // right, down, left, up
        int rows = matrix.size(), cols = matrix[0].size();
        int down = 0, right = 0, mode = 0;
        bool justswitched = false;
        std::vector<int> ret(rows * cols, 0);
        std::vector<std::pair<int, int>> increments{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        std::vector<int> limits{cols - 1, rows - 1, 0, 0};

        // finishing right decrements up, finishing down decrements right, finishing left decrements down, finishing up decrements left.

        std::vector<int *> vars{&right, &down, &right, &down};
        std::cout << "test1" << std::endl;
        int count = 0;
        while (true)
        {
            if (count > 100)
                break;
            std::cout << *vars[mode] << " " << limits[mode] << " " << down << " " << right << " " << std::endl;
            if (*vars[mode] == limits[mode])
            {
                std::cout << "met" << std::endl;
                if (justswitched)
                    break;
                int targetlimit = (--mode < 0) ? 3 : mode;
                if (targetlimit < 2)
                    --limits[targetlimit];
                else
                    ++limits[targetlimit];
                mode = (mode == 3) ? 0 : mode + 1;
                justswitched = true;
                continue;
            }
            // std::cout << "test2" << std::endl;
            justswitched = false;
            // std::cout << x << " " << y << std::endl;
            ret[count] = matrix[down][right];
            down += increments[mode].first;
            right += increments[mode].second;
            count++;
        }
        std::cout << std::endl;
        for (auto x : ret) std::cout << x;
        std::cout << std::endl;
        return ret;
    }
};

int main()
{
    std::vector<std::vector<int>> mat1{
        std::vector<int>{1, 2, 3, 4}, std::vector<int>{5, 6, 7, 8}, std::vector<int>{9, 10, 11, 12}, std::vector<int>{13, 14, 15, 16}};
    Solution s;
    std::cout << "test" << std::endl;
    auto x = s.getSpiral(mat1);
    return 0;
}