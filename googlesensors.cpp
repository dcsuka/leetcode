#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

template <typename T>
void print(const T &myT)
{
    for (T x : myT)
        cout << x;
    cout << endl;
}

class Solution
{
public:
    bool canCross(vector<vector<int>> sensors, int &maxDown, int &maxRight)
    {
        vector<vector<int>> edges
    }
};

int main()
{
    Solution a;
    vector<vector<int>> vec1{{1, 1, 5}, {1, 3, 5}, {1, 5, 5}, {1, 7, 5}, {1, 9, 5}};
    assert(!a.canCross(vec1, 10, 10));
    vector<vector<int>> vec2{{1, 1, 5}, {1, 5, 5}, {1, 7, 5}, {1, 9, 5}};
    assert(a.canCross(vec2, 10, 10));
    vector<vector<int>> vec2{{1, 1, 5}, {1, 5, 5}, {1, 7, 5}, {1, 9, 5}, {1, 5, 7}, {1, 3, 7}, {1, 1, 7}};
    assert(!a.canCross(vec2, 10, 10))
}