#pragma once
#include "SortingStrategy.h"

class SortByName : public SortingStrategy
{
public:
    void sort(std::vector<std::string>& data) const override;
};

