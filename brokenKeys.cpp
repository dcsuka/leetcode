#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int brokenKeys(int n, int key) {
        if (n == 0) return 0;
        string s = to_string(n);
        int lim = s.size();
        char filler = (key == 9) ? '8' : '9', broken = '0' + key;
        bool found = false;
        for (int i = 0; i < lim; ++i) {
            char &c = s[i];
            if (found) c = filler;
            else if (c == broken) {
                if (broken == '0') {
                    c = '9';
                    --s[i - 1];
                }
                else --c;
                found = true;
            }
        }
        return stoi(s);
    }
};

int main() {
    Solution sol;
    cout << sol.brokenKeys(456789, 7) << endl;
    cout << sol.brokenKeys(456789, 5) << endl;
    cout << sol.brokenKeys(9, 9) << endl;
    cout << sol.brokenKeys(4, 4) << endl;
    cout << sol.brokenKeys(12356, 4) << endl;
    cout << sol.brokenKeys(4569999, 9) << endl;
    cout << sol.brokenKeys(11003, 0) << endl;
    cout << sol.brokenKeys(5003, 0) << endl;
    cout << sol.brokenKeys(5003, 5) << endl;
    cout << sol.brokenKeys(0, 0) << endl;
    return 0;
}