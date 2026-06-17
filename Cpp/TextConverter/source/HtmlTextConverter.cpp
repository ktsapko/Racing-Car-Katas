
#include "../include/HtmlTextConverter.h"
#include "../include/FileReader.h"
#include "StringEscapeUtils.h"

HtmlTextConverter::HtmlTextConverter(std::string const &fullFilenameWithPath) : m_fullFilenameWithPath(fullFilenameWithPath)
{
}

std::string HtmlTextConverter::convertToHtml()
{
    FileReader fileReader(m_fullFilenameWithPath);

    auto lines = fileReader.readLines();

    std::string html;

    for (const auto &line : lines)
    {
        html += StringEscapeUtils::escapeHtml(line);
        html += "<br />";
    }
    return html;
}

std::string HtmlTextConverter::getFilename()
{
    return m_fullFilenameWithPath;
}
