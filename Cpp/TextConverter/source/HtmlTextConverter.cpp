
#include "../include/HtmlTextConverter.h"
#include "../include/FileReader.h"
#include "StringEscapeUtils.h"

HtmlTextConverter::HtmlTextConverter(IDataSource &source) : m_source(source)
{
}

std::string HtmlTextConverter::convertToHtml()
{
    auto lines = m_source.readLines();

    std::string html;

    for (const auto &line : lines)
    {
        html += StringEscapeUtils::escapeHtml(line);
        html += "<br />";
    }
    return html;
}

// std::string HtmlTextConverter::getFilename()
// {
//     return m_fullFilenameWithPath;
// }
