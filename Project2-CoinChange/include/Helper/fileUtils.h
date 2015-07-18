#pragma once

#include <fstream>
#include <string>
#include <vector>
namespace Helper
{
    void processCoinFile(std::ifstream &inStream, std::vector<std::vector<int>> &returnCoinLists,
                                 std::vector<int> &returnTotalValue);
    std::vector<std::string>* readLinesFromFile(std::ifstream&);
    void stripBrackets(std::string&);
    std::vector<int> csvToInt(std::string&);
    void WriteResultsToFile(std::ofstream&, std::vector<int>&, int);
}