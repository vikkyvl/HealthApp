#include "SortByDate.h"
#include <algorithm>
#include <sstream>

bool compareByDate(const std::string& plan1, const std::string& plan2)
{
    std::istringstream iss1(plan1);
    std::istringstream iss2(plan2);
    std::string name1, date1, time1, duration1;
    std::string name2, date2, time2, duration2;
    iss1 >> name1 >> date1 >> time1 >> duration1;
    iss2 >> name2 >> date2 >> time2 >> duration2;

    return date1 < date2;
}

void SortByDate::sort(std::vector<std::string>& data) const
{
    std::sort(data.begin(), data.end(), compareByDate);
}