#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

using tup = tuple<int ,int, int>;

class Solution {
public:
    int DIR[5] = {-1, 0, 1, 0, -1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size(), solidsum = 0, maxheight = 0, ret = 0;
        auto lam = [&heightMap] (const tup &a, const tup &b) {return heightMap[get<0>(a)][get<1>(a)] > heightMap[get<0>(b)][get<1>(b)];};

        if (m < 3 || n < 3) return 0;
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
                if (heightMap[i][j] < maxheight) pq.emplace_back(tuple(i, j, 0));
                visited[i][j] = true;
            }
        }

        for (int i = 0; i < m; i += m - 1) {
            for (int j = 1; j < n - 1; ++j) {
                if (heightMap[i][j] < maxheight) pq.emplace_back(tuple(i, j, 0));
                visited[i][j] = true;
            }
        }

        make_heap(pq.begin(), pq.end(), lam);

        while(pq.size()) {
            pop_heap(pq.begin(), pq.end(), lam);
            tup top = pq.back(); pq.pop_back();
            ret -= (maxheight - max(get<2>(top), heightMap[get<0>(top)][get<1>(top)]));
            for (int z = 0; z < 4; ++z) {
                int a = get<0>(top) + DIR[z], b = get<1>(top) + DIR[z + 1];
                if (a < 0 || a == m || b < 0 || b == n || visited[a][b] || heightMap[a][b] == maxheight) continue;
                pq.push_back(tuple(a, b, max(get<2>(top), heightMap[get<0>(top)][get<1>(top)])));
                push_heap(pq.begin(), pq.end(), lam);
                visited[a][b] = true;
            }
        }

        return ret;
    }
};

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

template <typename T>
void print (const T &myT) {
    for (auto &a : myT) std::cout << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << "  ";
    std::cout << std::endl;
}

class NewSolution {
public:
    int DIR[5] = {-1, 0, 1, 0, -1};
    bool debug = false;
    const int trapRainWater(vector<vector<int>>& heightMap) {
        int ret = 0, m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        vector<tup> q;
        auto lam = [&heightMap](const tup &a, const tup &b) {
            return heightMap[get<0>(a)][get<1>(a)] > heightMap[get<0>(b)][get<1>(b)];
        };
        for (int i = 0; i < m; ++i) {
            if (i == 0 || i == m - 1) {
                for (int j = 0; j < n; ++j) {
                    q.emplace_back(i, j, 0);
                    visited[i][j] = true;
                }
            }
            else {
                q.emplace_back(i, 0, 0); q.emplace_back(i, n - 1, 0);
                visited[i][0] = true; visited[i][n - 1] = true;
            }
        }
        make_heap(q.begin(), q.end(), lam);
        while (q.size()) {
            if (debug) print(q);
            pop_heap(q.begin(), q.end(), lam);
            tup curr = q.back(); q.pop_back();
            int currheight = heightMap[get<0>(curr)][get<1>(curr)];
            ret += max(0, get<2>(curr) - currheight);
            if (debug) cout << ret << endl;
            for (int z = 0; z < 4; ++z) {
                int a = get<0>(curr) + DIR[z];
                int b = get<1>(curr) + DIR[z + 1];
                if (a < 0 || a == m || b < 0 || b == n || visited[a][b]) continue;
                q.emplace_back(a, b, max(currheight, get<2>(curr)));
                push_heap(q.begin(), q.end(), lam);
                visited[a][b] = true;
            }
        }
        return ret;
    }
};

template <typename T>
void timeit(T &obj) {
    vector<vector<int>> v3 {{3,1,3,3,3},{3,1,1,1,3},{3,1,1,1,3},{3,1,1,1,3},{3,3,3,3,3}};
    vector<vector<int>> v1 {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    vector<vector<int>> v2 {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    vector<vector<int>> v4 {{1}};
    vector<vector<int>> v5 {{18,13,13,17,12,11},{17,2,6,10,5,10},{11,10,2,8,8,2},{12,6,10,8,8,7},{18,4,7,6,7,4},{20,5,9,2,3,10}};
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        obj.trapRainWater(v3);
        obj.trapRainWater(v1);
        obj.trapRainWater(v2);
        obj.trapRainWater(v4);
        obj.trapRainWater(v5);        
    }
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
}

int main() {
    Solution s;
    NewSolution sol;
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
    //timeit(s);
    //timeit(sol);
    return 0;

}