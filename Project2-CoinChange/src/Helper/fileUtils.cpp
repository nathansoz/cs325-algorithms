#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

#include "../../include/Helper/fileUtils.h"

std::vector<std::string>* Helper::readLinesFromFile(std::ifstream& inFromFile)
{
    std::vector<std::string>* returnStrings = new std::vector<std::string>();

    std::string curLine;
    while(std::getline(inFromFile, curLine))
    {
        returnStrings->push_back(curLine);
    }

    return returnStrings;

}

void Helper::stripBrackets(std::string &stripString)
{
    std::string retString;

    for(uint i = 0; i < stripString.length(); i++)
    {
        if(stripString.at(i) == '[' || stripString.at(i) == ']')
            continue;
        else
            retString += stripString.at(i);
    }

    stripString = retString;
}

std::vector<int> Helper::csvToInt(std::string &convertString)
{
    std::vector<int> returnVector;
    const char *cstrConvertString = convertString.c_str();

    char* tmpString = strtok((char*)cstrConvertString, " ,");
    while(tmpString != NULL)
    {
        int tmp = atoi(tmpString);
        returnVector.push_back(tmp);
        tmpString = strtok(NULL, " ,");
    }

    return returnVector;
}

void Helper::processCoinFile(std::ifstream &inStream, std::vector<std::vector<int>> &returnCoinLists,
                             std::vector<int> &returnTotalValue)
{
    std::vector<std::string>* CoinFileLines = Helper::readLinesFromFile(inStream);

    for(uint i = 0; i < CoinFileLines->size(); i++)
    {
        Helper::stripBrackets(CoinFileLines->at(i));

        //
        if(i % 2 == 0)
            returnCoinLists.push_back(Helper::csvToInt(CoinFileLines->at(i)));
        else
            returnTotalValue.push_back(atoi(CoinFileLines->at(i).c_str()));
    }
}

void Helper::WriteResultsToFile(std::ofstream &outStream, std::vector<int>& coinCount, int total)
{
    outStream << "[";
    for(uint i = 0; i < coinCount.size() - 1; i++)
        outStream << coinCount.at(i) << ", ";
    outStream << coinCount.at(coinCount.size() - 1) << "]" << std::endl;

    outStream << total << std::endl;
}
