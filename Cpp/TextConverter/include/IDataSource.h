#pragma once
#include <string>
#include <vector>

class IDataSource
{
public:
    virtual ~IDataSource() = default;
    virtual std::vector<std::string> readLines() = 0;
};
