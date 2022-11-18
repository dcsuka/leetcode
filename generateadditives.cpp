#include <iostream>
#include <string>
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
    vector<int> generateAdditives(int low, int high) {
        string h = to_string(high);
        int hs = h.size(), lim = stoi(h.substr(0, hs / 2));
        vector<int> ret;
        for (int i = 1; i <= lim; ++i) {
            int curr = i, prev = i;
            string mystring = to_string(prev) + to_string(curr);
            while (true) {
                int next = curr + prev;
                string ns = to_string(next);
                if (mystring.size() + ns.size() > hs) break;
                mystring += ns;
                int trial = stoi(mystring);
                if (low <= trial && trial <= high) ret.emplace_back(trial);
                prev = curr;
                curr = next;
            }
        }
        //Just a touch
        sort(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution sol;
    print(sol.generateAdditives(7000, 20000));
    print(sol.generateAdditives(0, 999999999));
    return 0;
}