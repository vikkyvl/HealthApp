#pragma once
#include "SortingStrategy.h"

class SortByDate : public SortingStrategy
{
public:
    void sort(std::vector<std::string>& data) const override;
};

