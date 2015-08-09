#pragma once

#include <fstream>
#include <string>
#include <vector>
namespace Helper
{
    std::vector<std::string>* readLinesFromFile(std::ifstream&);
    std::vector<int> csvToInt(std::string&);
}