#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tup = tuple<int ,int, int, int>;

void print (const vector<tup> &myT) {
    for (auto &x : myT) std::cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << " " << get<3>(x) << endl;
    std::cout << std::endl;
}

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

//i, j, height, minNeighbor


bool Compare(const tup &a, const tup &b) {
    return get<2>(a) > get<2>(b);
}

class Solution {
public:
    int DIR[5] = {-1, 0, 1, 0, -1};
    bool debug = false;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size(), solidsum = 0, maxheight = 0, ret = 0;
        if (m <= 1 || n <= 1) return 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                solidsum += heightMap[i][j];
                maxheight = max(maxheight, heightMap[i][j]);
            }
        }

        ret = m * n * maxheight - solidsum;
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        vector<tup> pq;
        pq.reserve(2 * m + 2 * n - 4);

        //left, right, get corners too
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j += n - 1) {
                pq.emplace_back(tuple(i, j, heightMap[i][j], 0));
                visited[i][j] = true;
            }
        }

        for (int i = 0; i < m; i += m - 1) {
            for (int j = 1; j < n - 1; ++j) {
                pq.emplace_back(tuple(i, j, heightMap[i][j], 0));
                visited[i][j] = true;
            }
        }

        make_heap(pq.begin(), pq.end(), Compare);

        while(pq.size()) {
            if (debug) print(pq);
            if (debug) cout << ret << endl;
            pop_heap(pq.begin(), pq.end(), Compare);
            tup top = pq.back(); pq.pop_back();
            if (debug) std::cout << get<0>(top) << " " << get<1>(top) << " " << get<2>(top) << " " << get<3>(top) << endl << endl;
            if (debug) print(visited);
            ret -= (maxheight - max(get<2>(top), get<3>(top)));
            for (int z = 0; z < 4; ++z) {
                int a = get<0>(top) + DIR[z], b = get<1>(top) + DIR[z + 1];
                if (a < 0 || a == m || b < 0 || b == n || visited[a][b]) continue;
                pq.push_back(tuple(a, b, heightMap[a][b], max(get<2>(top), get<3>(top))));
                push_heap(pq.begin(), pq.end(), Compare);
                visited[a][b] = true;
            }
        }

        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v3 {{3,1,3,3,3},{3,1,1,1,3},{3,1,1,1,3},{3,1,1,1,3},{3,3,3,3,3}};
    cout << sol.trapRainWater(v3) << " == 0" << endl;
    vector<vector<int>> v1 {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout << sol.trapRainWater(v1) << " == 4" << endl;
    vector<vector<int>> v2 {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    cout << sol.trapRainWater(v2) << " == 10" << endl;
    vector<vector<int>> v4 {{1}};
    cout << sol.trapRainWater(v4) << " == 0" << endl;
    vector<vector<int>> v5 {{18,13,13,17,12,11},{17,2,6,10,5,10},{11,10,2,8,8,2},{12,6,10,8,8,7},{18,4,7,6,7,4},{20,5,9,2,3,10}};
    cout << sol.trapRainWater(v5) << " == 18" << endl;
    return 0;
}

/*

*/