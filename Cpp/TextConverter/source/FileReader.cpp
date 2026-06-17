#include "../include/FileReader.h"

FileReader::FileReader(std::string const &fileNameWithPath) : m_fullFilenameWithPath(fileNameWithPath)
{
}

std::vector<std::string> FileReader::readLines()
{
    std::ifstream file(m_fullFilenameWithPath);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + m_fullFilenameWithPath);
    }

    std::vector<std::string> lines;

    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}