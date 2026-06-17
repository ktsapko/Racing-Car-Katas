
#include "../include/HtmlTextConverter.h"
#include "../include/StringEscapeUtils.h"
#include <iostream>

HtmlTextConverter::HtmlTextConverter(std::string const& fullFilenameWithPath) : m_fullFilenameWithPath(fullFilenameWithPath)
{}

std::string HtmlTextConverter::convertToHtml() 
{
    std::ifstream reader;
    std::cout << "File: [" << m_fullFilenameWithPath << "]\n";
    reader.open(m_fullFilenameWithPath);
    if (!reader.is_open())
    {
        throw std::runtime_error("Could not open file: " + m_fullFilenameWithPath);
    }

    std::string line;
    std::string html;
    while (std::getline(reader,line))
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
