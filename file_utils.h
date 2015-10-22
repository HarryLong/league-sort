#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>
#include <functional>

namespace FileUtils{
    bool exists(const std::string & filename);
}

namespace StringUtils{
    std::vector<std::string> splitAtFirstOccurence(const std::string & s, char c);
    std::vector<std::string> splitAtLastOccurence(const std::string & s, char c);
    std::vector<std::string> splitAtIndex(const std::string & s, int index);

    std::string& trim(std::string & input);
    std::string& leftTrim(std::string & input);
    std::string& rightTrim(std::string & input);
}

#endif // FILE_UTILS_H
