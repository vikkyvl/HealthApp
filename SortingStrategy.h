#pragma once
#include <vector>
#include <string>

class SortingStrategy
{
public:
    virtual void sort(std::vector<std::string>& data) const = 0;
    virtual ~SortingStrategy() {}
};

