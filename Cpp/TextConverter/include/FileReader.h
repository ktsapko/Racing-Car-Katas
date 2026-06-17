#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

class FileReader
{
private:
    std::string m_fullFilenameWithPath;

public:
    explicit FileReader(std::string const &fileNameWithPath);
    ~FileReader() = default;

    std::vector<std::string> readLines();
};

#endif // FILE_READER_H
