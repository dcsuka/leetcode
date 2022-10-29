#include <iostream>
#include <stdint.h>
#include <bitset>
#include <cmath>
#include <random>
#include <cassert>

// Encodes two 32 bit signed integers into one 64 bit unsigned integer, then decodes

using namespace std;

using intPair = pair<int, int>;

class Solution
{
public:
    uint64_t encode(intPair x)
    {
        return ((uint64_t)(x.first < 0) << 63) | ((uint64_t)(abs(x.first)) << 32) | (abs(x.second)) | ((uint64_t)(x.second < 0) << 31);
    }
    intPair decode(uint64_t y)
    {
        int first = ((y >> 32) & ((0b1111111111111111111111111111111)));
        // cout << bitset<32>(first) << endl;
        int second = (y & ((0b1111111111111111111111111111111)));
        // cout << bitset<32>(second) << endl;
        // cout << bitset<32>((y >> 31) & 1) << endl;
        return intPair(((y >> 63) & 1) ? -first : first, ((y >> 31) & 1) ? -second : second);
    }
};

void prettyPrint(int a, int b)
{
    Solution s;
    cout << "Integer a is " << a << ", " << bitset<32>(a) << endl;
    cout << "Integer a is " << b << ", " << bitset<32>(b) << endl;
    uint64_t x = s.encode(intPair(a, b));
    cout << "Encoded is " << x << ", " << bitset<64>(x) << endl;
    intPair d = s.decode(x);
    cout << "Decoded: " << endl;
    cout << "Integer a is " << d.first << ", " << bitset<32>(d.first) << endl;
    cout << "Integer a is " << d.second << ", " << bitset<32>(d.second) << endl;
    cout << ((d == intPair(a, b)) ? "Passed" : "Failed") << endl
         << endl;
}

int main()
{
    prettyPrint(-164, -12);
    prettyPrint(-38450324, -32423434);
    prettyPrint(124243, 32423480);
    prettyPrint(INT_MAX, INT_MAX - 100);
    prettyPrint(INT_MAX - 4759, INT_MAX - 324);
    prettyPrint(INT_MIN + 1, INT_MIN + 1);
    prettyPrint(INT_MIN, INT_MIN + 1);
    // Having one INT_MIN fails

    Solution s;
    random_device rd;
    default_random_engine dre(rd());
    uniform_int_distribution uid(INT_MIN + 1, INT_MAX);

    for (int i = 0; i < 10000; ++i)
    {
        int x = uid(dre);
        int y = uid(dre);
        if (i % 100 == 0)
            cout << x << " " << y << endl;
        intPair myPair = intPair(x, y);
        assert(myPair == s.decode(s.encode(myPair)));
    }
    return 0;
}