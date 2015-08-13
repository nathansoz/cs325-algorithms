#include <vector>
#include <cmath>

#include "../include/TSP_Solver.h"

//tmp debugging header
#include <iostream>
#include <string.h>
#include <limits.h>
#include <boost/thread.hpp>

//Public Implementation HERE




TSP_Solver::TSP_Solver(std::istream &inFile)
{
    this->bestResult = INT_MAX;

    //Init heap objects
    this->cities = new std::vector<TSP_City*>();
    this->bestTour = new std::vector<int>();
    std::vector<std::string>* fileLines = this->readLinesFromFile(inFile);
    PopulateCities(fileLines);

    //cleanup temp objects
    delete fileLines;
}

TSP_Solver::~TSP_Solver()
{
    for(int i = 0; i < cities->size(); i++)
        delete cities->at(i);

    delete cities;
}

void TSP_Solver::PrintBestTour(std::ostream &out)
{
    out << bestResult << std::endl;

    for(int i = 0; i < bestTour->size(); i++)
    {
        out << this->bestTour->at(i) << std::endl;
    }
}

void TSP_Solver::SolveWithNearestNeighbor()
{
    boost::thread* solver = new boost::thread(&TSP_Solver::threaded_SolveWithNearestNeighbor, this);

    for(int i = 0; i < ((60 * 4) + 30); i++)
    {
        if(solver->timed_join(boost::posix_time::time_duration(0,0,1,0)))
        {
            //std::cout << "Thread exit\n";
            break;
        }

    }
    solver->interrupt();
    std::cout << "We timed out close to 5 minutes. The best result we got was: " << bestResult << std::endl;


}

//Private Implementation HERE

void TSP_Solver::threaded_SolveWithNearestNeighbor()
{
    std::cout << "We will compute " << this->cities->size() << " passes." << std::endl;

    for(int i = 0; i < cities->size(); i++)
    {
        this->workingTour = new std::vector<int>();

        int result = NearestNeighborFromCity(cities->at(i));
        if(result < this->bestResult)
        {
            this->bestResult = result;
            std::vector<int> *tmp = bestTour;
            this->bestTour = workingTour;
            delete tmp;
        }
        this->ResetVisited();

        std::cout << "The current best result is " << bestResult << std::endl;
    }


}

//probably don't have to do this check.. consider using a counter instead.
bool TSP_Solver::AllCitiesVisited()
{
    for(int i = 0; i < cities->size(); i++) {
        if (cities->at(i)->visited)
            continue;
        else
        {
            return false;
        }
    }

    return true;

}

int TSP_Solver::ComputeDistance(int x1, int y1, int x2, int y2)
{
    double trueDistance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    return static_cast<int>(lrint(trueDistance));
}

int TSP_Solver::NearestNeighborFromCity(TSP_City *city)
{
    if(cities->size() == 0)
        return -1;

    TSP_City* currentCity = city;
    int distanceTraveled = 0;

    for (int i = 0; i < cities->size(); i++)
    {
        TSP_City* nextCity = FindClosestCity(currentCity);

        if(nextCity == NULL)
        {
            this->workingTour->push_back(currentCity->id);
            //std::cout << ComputeDistance(currentCity->x, currentCity->y,
            //                            city->x, city->y) << std::endl;
            distanceTraveled += ComputeDistance(currentCity->x, currentCity->y,
                                                city->x, city->y);
            break;
        }
        //std::cout << ComputeDistance(currentCity->x, currentCity->y,
        //                             nextCity->x, nextCity->y) << std::endl;
        distanceTraveled += ComputeDistance(currentCity->x, currentCity->y,
                                            nextCity->x, nextCity->y);

        currentCity->visited = true;
        this->workingTour->push_back(currentCity->id);
        currentCity = nextCity;
    };

    return distanceTraveled;
}

void TSP_Solver::PopulateCities(std::vector<std::string> *fileLines)
{
    std::vector<std::vector<int>*>* values = this->vectorizeLines(fileLines);

    for(int i = 0; i < values->size(); i++)
    {
        std::vector<int> *curLine = values->at(i);
        //Corner case of blank line in file
        if(curLine->size() == 0)
            continue;

        TSP_City *city = new TSP_City();

        city->id = curLine->at(CITY_ID);
        city->x = curLine->at(X_COORD);
        city->y = curLine->at(Y_COORD);
        city->visited = false;

        this->cities->push_back(city);
    }

    for(int i = 0; i < values->size(); i++)
        delete values->at(i);
    delete values;
}

TSP_City* TSP_Solver::FindClosestCity(TSP_City *city)
{
    TSP_City* currentCity = city;
    TSP_City* closestCitySoFar = NULL;
    int smallestDistance = INT_MAX;

    for(int i = 0; i < cities->size(); i++)
    {

        TSP_City *potentialNextCity = cities->at(i);
        int distanceToPotentialNextCity = ComputeDistance(currentCity->x, currentCity->y, potentialNextCity->x, potentialNextCity->y);

        if(city == cities->at(i))
            continue;

        if(closestCitySoFar == NULL && !potentialNextCity->visited)
        {
            closestCitySoFar = cities->at(i);
            smallestDistance = distanceToPotentialNextCity;
        }
        else if(distanceToPotentialNextCity < smallestDistance && !potentialNextCity->visited)
        {
            closestCitySoFar = potentialNextCity;
            smallestDistance = distanceToPotentialNextCity;
        }
    }

    return closestCitySoFar;
}

std::vector<std::string>* TSP_Solver::readLinesFromFile(std::istream& inFromFile)
{
    std::vector<std::string>* returnStrings = new std::vector<std::string>();

    std::string curLine;
    while(std::getline(inFromFile, curLine))
    {
        returnStrings->push_back(curLine);
    }

    return returnStrings;

}

void TSP_Solver::ResetVisited()
{
    for(int i = 0; i < cities->size(); i++)
        cities->at(i)->visited = false;

}

std::vector<std::vector<int>*>* TSP_Solver::vectorizeLines(std::vector<std::string>* fileLines)
{
    std::vector<std::vector<int>*>* returnVector = new std::vector<std::vector<int>*>();

    for(int i = 0; i < fileLines->size(); i++)
        returnVector->push_back(this->spaceToInt(fileLines->at(i)));

    return returnVector;
}

std::vector<int>* TSP_Solver::spaceToInt(std::string &convertString)
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