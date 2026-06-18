#pragma once
#include "IDataSource.h"
#include <string>
#include <fstream>

class HtmlTextConverter
{

public:
    explicit HtmlTextConverter(IDataSource &source);

    std::string convertToHtml();

private:
    IDataSource &m_source;
};
