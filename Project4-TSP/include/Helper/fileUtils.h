#pragma once

#include <fstream>
#include <string>
#include <vector>
namespace Helper
{
    std::vector<std::string>* readLinesFromFile(std::ifstream&);
    std::vector<int> spaceToInt(std::string&);
    std::vector<std::vector<int>> vectorizeLines(std::vector<std::string>*);
    boost::adjacency_list* createGraph(std::vector<std::string>*);
}