
#include "../include/HtmlPagesConverter.h"
#include "../include/StringEscapeUtils.h"
#include "../include/FileReader.h"

#include <sstream>

HtmlPagesConverter::HtmlPagesConverter(IDataSource &source) : m_source(source)
{
    // FileReader reader(m_filename);

    auto lines = m_source.readLines();

    m_breaks.push_back(0);

    for (size_t i = 0; i < lines.size(); ++i)
    {
        if (lines[i] == "PAGE_BREAK")
        {
            m_breaks.push_back(i + 1);
        }
    }
}

std::string HtmlPagesConverter::getHtmlPage(int page)
{
    std::ostringstream htmlPage;

    auto lines = m_source.readLines();

    size_t start = m_breaks[page];

    for (size_t i = start; i < lines.size(); ++i)
    {
        if (lines[i] == "PAGE_BREAK")
            break;

        htmlPage << StringEscapeUtils::escapeHtml(lines[i]);
        htmlPage << "<br />";
    }
    return htmlPage.str();
}

