#include "SortByName.h"
#include <algorithm>
#include <sstream>

bool compareByName(const std::string& plan1, const std::string& plan2)
{
    std::istringstream iss1(plan1);
    std::istringstream iss2(plan2);
    std::string name1, name2;
    iss1 >> name1;
    iss2 >> name2;

    return name1 < name2;
}

void SortByName::sort(std::vector<std::string>& data) const
{
    std::sort(data.begin(), data.end(), compareByName);
}
