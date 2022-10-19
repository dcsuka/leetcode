#include <iostream>

int main()
{
    for (int i = 1; i <= 100; ++i)
    {
        bool fizz = i % 3 == 0, buzz = i % 5 == 0;
        if (fizz && buzz)
        {
            std::cout << "fizzbuzz" << std::endl;
        }
        else if (fizz)
        {
            std::cout << "fizz" << std::endl;
        }
        else if (buzz)
        {
            std::cout << "buzz" << std::endl;
        }
        else
        {
            std::cout << i << std::endl;
        }
    }
}