#pragma once
#include <string>
#include <vector>
#include "IDataSource.h"

class HtmlPagesConverter
{
    std::vector<int> m_breaks;

public:
    explicit HtmlPagesConverter(IDataSource &source);

    std::string getHtmlPage(int page);

    std::string getFilename();

private:
    IDataSource &m_source;
};
