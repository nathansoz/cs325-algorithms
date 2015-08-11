#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <cmath>



#include "../../include/Helper/fileUtils.h"

#define CITY_ID 0
#define X_COORD 1
#define Y_COORD 2

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

std::vector<std::vector<int>*>* Helper::vectorizeLines(std::vector<std::string>* fileLines)
{
    std::vector<std::vector<int>*>* returnVector = new std::vector<std::vector<int>*>();

    for(int i = 0; i < fileLines->size(); i++)
        returnVector->push_back(spaceToInt(fileLines->at(i)));

    return returnVector;
}


//This function will be useful, it just needs to be converted to space separated values
std::vector<int>* Helper::spaceToInt(std::string &convertString)
{
    std::vector<int>* returnVector = new std::vector<int>();
    const char *cstrConvertString = convertString.c_str();

    char* tmpString = strtok((char*)cstrConvertString, " ");
    while(tmpString != NULL)
    {
        int tmp = atoi(tmpString);
        returnVector->push_back(tmp);
        tmpString = strtok(NULL, " ");
    }

    return returnVector;
}

//this function should be moved into is own thing...
int computeCityDistance(int x1, int y1, int x2, int y2)
{
    double trueDistance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    return static_cast<int>(lrint(trueDistance));
}

Graph* Helper::createGraph(std::vector<std::string>* fileLines)
{
    //this method of init taken from:
    // http://stackoverflow.com/questions/24366642/how-do-i-change-the-edge-weight-in-a-graph-using-the-boost-graph-library

    Graph* returnGraph = new Graph();

    std::vector<std::vector<int>*>* values = vectorizeLines(fileLines);
    std::cout << "lines vectorized" << std::endl;

    //for(int i = 0; i < values->size(); i++)
        //boost::add_vertex(values->at(i)->at(CITY_ID), *returnGraph);

    for(int i = 0; i < values->size(); i++)
    {
        if(values->at(i)->size() == 0)
            continue;

        int originID = values->at(i)->at(CITY_ID);
        int originX = values->at(i)->at(X_COORD);
        int originY = values->at(i)->at(Y_COORD);

        for(int j = 0; j < values->size(); j++)
        {
            std::cout << "Adding " << i << "to " << j << std::endl;

            if(i == j || values->at(j)->size() == 0)
                continue;

            int destID = values->at(j)->at(CITY_ID);
            int destX = values->at(j)->at(X_COORD);
            int destY = values->at(j)->at(Y_COORD);


            int distance = computeCityDistance(originX, originY, destX, destY);

            std::pair<Graph::edge_descriptor, bool> ed = boost::add_edge(originID, destID, *returnGraph);
            (*returnGraph)[ed.first].distance = distance;


            //now set the vertex property to not visited
            Graph::vertex_descriptor a, b;

            a = boost::source(ed.first, *returnGraph);
            b = boost::target(ed.first, *returnGraph);
            (*returnGraph)[a].visited = false;
            (*returnGraph)[b].visited = false;


        }
    }

    return returnGraph;
}






