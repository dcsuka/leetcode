#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

static std::vector<int> generate_data(size_t size)
{
    // We use static in order to instantiate the random engine
    // and the distribution once only.
    // It may provoke some thread-safety issues.
    std::random_device rd;
    std::default_random_engine dre(rd());
    std::uniform_int_distribution<int> uid(INT_MIN / 5, INT_MAX / 5);

    /*
    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(cards_), std::end(cards_), rng);*/
    std::cout << uid(dre) << std::endl;

    std::vector<int> data(size);
    std::generate(data.begin(), data.end(), [&uid, &dre]()
                  { return uid(dre); });
    return data;
}

int main()
{
    for (auto i = 0u; i < 5; ++i)
    {
        std::vector<int> myVector = generate_data(10);
        myVector = generate_data(10);

        std::cout << "myVector (iteration " << i << "): ";
        for (auto v : myVector)
        {
            std::cout << v << ",";
        }
        std::cout << "\n";
    }
}