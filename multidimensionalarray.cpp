#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    const int mm = m;
    const int nn = n;
    constexpr size_t mmm = mm;
    constexpr size_t nnn = nn;
    
    cout << s.find_first_not_of(s[0]) << endl;
    return 0;
}