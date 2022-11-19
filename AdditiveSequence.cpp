#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string s) {
        int n = s.size(), lim = n * 2 / 3;
        for (int i = 2; i <= lim; ++i) {
            for (int j = 1; j < i; ++j) {
                string curr = s.substr(j, i - j);
                string prev = s.substr(0, j);
                if ((curr[0] == '0' && curr.size() > 1) || (prev[0] == '0' && prev.size() > 1)) continue;
                string mystring = prev + curr;
                long currint = stol(curr);
                long prevint = stol(prev);
                while (true) {
                    long nextint = currint + prevint;
                    string next = to_string(nextint);
                    if (next.size() + mystring.size() > n) break;
                    mystring += next;
                    if (mystring == s) return true;
                    prevint = currint;
                    currint = nextint;
                }
            }
        }
        return false;
    }
};

class SOSolution {
public:
        bool isAdditiveNumber(string num) {
            for(int i=1; i<=num.size()/2; i++){
                for(int j=1; j<=(num.size()-i)/2; j++){
                    if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
                }
            }
            return false;
        }
        bool check(string num1, string num2, string num){
            if(num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;
            string sum=add(num1, num2);
            if(num==sum) return true;
            if(num.size()<=sum.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
            else return check(num2, sum, num.substr(sum.size()));
        } 
        string add(string n, string m){
            string res;
            int i=n.size()-1, j=m.size()-1, carry=0;
            while(i>=0 || j>=0){
                int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
                res.push_back(sum%10+'0');
                carry=sum/10;
            }
            if(carry) res.push_back(carry+'0');
            reverse(res.begin(), res.end());
            return res;
        }
};

int main() {
    SOSolution sol;
    cout << sol.isAdditiveNumber("11235813") <<  " 1" << endl;
    cout << sol.isAdditiveNumber("99911000") <<  " 1" << endl;
    cout << sol.isAdditiveNumber("0112") <<  " 1" << endl;
    cout << sol.isAdditiveNumber("112") <<  " 1" << endl;
    cout << sol.isAdditiveNumber("334477") <<  " 1" << endl;
    cout << sol.isAdditiveNumber("3304477") <<  " 0" << endl;
    cout << sol.isAdditiveNumber("3344778") <<  " 0" << endl;
    cout << sol.isAdditiveNumber("000") <<  " 1" << endl;
    cout << sol.isAdditiveNumber("011235") <<  " 1" << endl;
    cout << sol.isAdditiveNumber("0235813") <<  " 0" << endl;
    cout << sol.isAdditiveNumber("1991000199299498797") <<  " 0" << endl;
    return 0;
}
