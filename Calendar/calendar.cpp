#include <vector>
#include <iostream>
#include <algorithm>

class Calendar
{
public:
    void printCalendar(const std::string &startDay, const int &numDays)
    {
        std::vector<std::string> days{"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
        auto day = std::find(days.begin(), days.end(), startDay);
        if (day == days.end())
        {
            std::cout << "Please enter a valid title-case three-letter day abbreviation." << std::endl
                      << std::endl;
            return;
        }
        if (numDays < 1 || numDays > 31)
        {
            std::cout << "Please enter a valid number of days between 1 and 31." << std::endl
                      << std::endl;
            return;
        }
        int index = day - days.begin();
        for (int i = 0; i < index; ++i)
        {
            days[i] += "    ";
        }
        for (int count = 1; count <= numDays; ++count)
        {
            std::string curDay = (count < 10) ? " " + std::to_string(count) : std::to_string(count);
            days[index] += " " + curDay + " ";
            if (++index > 6)
                index = 0;
        }
        for (auto x : days)
        {
            std::cout << x << std::endl;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Calendar mycal;
    mycal.printCalendar("Sun", 31);
    mycal.printCalendar("Fri", 99);
    mycal.printCalendar("Tue", 28);
    mycal.printCalendar("Thu", 31);
    return 0;
}