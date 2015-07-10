#pragma once

#include <fstream>
#include <string>
#include <vector>
namespace Helper
{
    std::vector<std::vector<int>*>* processMSSFile(std::ifstream&);
    std::vector<std::string>* readLinesFromFile(std::ifstream&);
    void stripBrackets(std::string&);
    std::vector<int>* csvToInt(std::string&);
}