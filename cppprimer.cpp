#include <iostream>
#include <memory>
#include <string>

using namespace std;

void deleter(int *x)
{
    cout << "something deleted" << endl;
    delete x;
}

int main()
{
    /*    shared_ptr<int> q;
    {
        shared_ptr<int> p(new int(42), deleter);
        //q = p;
        cout << "boo" << endl;
    }
    cout << "ended" << endl;
    return 0;*/
    string x("");
    auto n = x.size();
    cout << n << endl;
    cout << --n << endl;
    cout << (n == -1) << endl;
    return 0;
}