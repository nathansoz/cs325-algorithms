/*
    File: linear.cpp
    Authors: Jen, Dale, and Nathan
    Description: Contains functions that run linear MSS algo
    Returns: MSS sum and (optional via reference) index values of bounds
*/

#include <vector>
#include <algorithm> // For std::max

#include "../include/linear.h"

int linear(std::vector<int> array)
{
    int maxToPoint = 0;
    int maxToReturn = 0;


    for(uint i = 0; i < array.size(); i++)
    {
        maxToPoint = std::max(0, maxToPoint + array[i]);
	maxToReturn = std::max(maxToPoint, maxToReturn);
    }

    return maxToReturn;
}

int linear(std::vector<int> array, int &start, int &end)
{
    int maxToPoint = 0;
    int maxToReturn = 0;

    start = 0;
    end = 0;

    for(uint i = 0; i < array.size(); i++)
    {
        if((maxToPoint + array[i]) < 0)
        {
            maxToPoint = 0;
            start = i + 1;
        }
        else
        {
            maxToPoint = maxToPoint + array[i];
        }
        if(maxToReturn < maxToPoint)
        {
            maxToReturn = maxToPoint;
            end = i;
        }
    }

    return maxToReturn;
}
