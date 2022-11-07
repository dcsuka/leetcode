#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print (const T &myT) {
    for (auto x : myT) std::cout << x << " ";
    std::cout << std::endl;
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size() - 1;
        while (j <= k) {
            if (nums.at(j) == 0) {
                swap(nums.at(i), nums.at(j));
                ++i;
                ++j;
            }
            else if (nums.at(j) == 1) ++j;
            else {
                swap(nums.at(j), nums.at(k));
                --k;
            }
        }
    }
};


int main() {
    vector<int> vec {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors(vec);
    print(vec);
    return 0;
}