/**********************************************************************
File: betterEnum.cpp

Description: Calculates the sum of an array by looping over indices i
and j but in O(1) time. Also calculates runtime of the function.

Parameters: vector of integers, size of vector

Pre-Conditions:

**************************************************************************/

#include "../include/betterEnum.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

void betterEnumFunction(std::vector <int> vec, int size)
{
	int max = 0, newSum = 0, start = 0, end = 0;
	double time = 0;
	clock_t startClock, endClock;

	startClock = clock();

	/*Iterate through array*/
	for (int i = 0; i < size; i++)
	{
		/*Reset newSum*/
		newSum = 0;
		for (int j = i; j < size; j++)
		{
			/*Calculate newSum*/
			newSum += vec[j];

			/*If we have a new max sum*/
			if (newSum > max)
			{
				start = i;
				end = j;
				max = newSum;
			}
		}
	}
	endClock = clock();

	time = ((double)(endClock - startClock) / CLOCKS_PER_SEC);
	std::cout << time << std::endl;
}