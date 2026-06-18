#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "IDataSource.h"

class FileReader : public IDataSource
{
public:
    explicit FileReader(const std::string &fileNameWithPath);
    ~FileReader() = default;

    std::vector<std::string> readLines() override;

private:
    std::string m_fullFilenameWithPath;
};
