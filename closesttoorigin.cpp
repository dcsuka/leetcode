#include <iostream>
#include <queue>
#include <algorithm>

using vint = std::vector<int>;

struct Comparator
{
    bool operator()(const vint &v1, const vint &v2)
    {
        return v1[0] + v1[1] > v2[0] + v2[1];
    }
};

bool Compare(const vint &v1, const vint &v2)
{
    return v1[0] + v1[1] < v2[0] + v2[1];
}

int main()
{
    // Closest points to origin question.

    // Approach 1: make a priority queue with a custom lambda comparator
    std::vector<vint> myvec{vint{35, 74}, vint{0, 1}, vint{5, 7}, vint{11, 15}, vint{2, 3}};
    auto comp = [](vint &a, vint &b)
    { return a[0] + a[1] > b[0] + b[1]; };
    std::priority_queue<vint, std::vector<vint>, decltype(comp)> myq(myvec.begin(), myvec.end(), comp);
    while (!myq.empty())
    {
        auto x = myq.top();
        std::cout << x[0] << " " << x[1] << std::endl;
        myq.pop();
    }
    std::cout << std::endl;

    // Approach 2: make a priority queue with a custom class comparator
    std::priority_queue<vint, std::vector<vint>, Comparator> myqueue(myvec.begin(), myvec.end());
    while (!myqueue.empty())
    {
        auto x = myqueue.top();
        std::cout << x[0] << " " << x[1] << std::endl;
        myqueue.pop();
    }
    std::cout << std::endl;

    // Approach 3: using partial quicksort to get the first 3 elements
    int n = 4;
    std::nth_element(myvec.begin(), myvec.begin() + n, myvec.end(), Compare);
    std::vector<vint> retvec(myvec.begin(), myvec.begin() + n);
    for (auto x : retvec)
    {
        std::cout << x[0] << " " << x[1] << std::endl;
    }
    std::cout << std::endl;
    return 0;
}