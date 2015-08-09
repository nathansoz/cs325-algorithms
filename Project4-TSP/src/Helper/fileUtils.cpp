#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>

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

/*
std::vector<std::vector<int>> Helper::vectorizeLines(std::vector<std::string>*)
{

}

 */

//This function will be useful, it just needs to be converted to space separated values
std::vector<int> Helper::spaceToInt(std::string &convertString)
{
    std::vector<int> returnVector;
    const char *cstrConvertString = convertString.c_str();

    char* tmpString = strtok((char*)cstrConvertString, " ");
    while(tmpString != NULL)
    {
        int tmp = atoi(tmpString);
        returnVector.push_back(tmp);
        tmpString = strtok(NULL, " ,");
    }

    return returnVector;
}

/*

boost::adjacency_list* Helper::createGraph(std::vector<std::string>*)
{

}

 */


