/**********************************************************************
File: enum.cpp

Description: Calculates the sum of an array by looping over indices i
and j. Also calculates runtime of the function.

Parameters: vector of integers, size of vector

Pre-Conditions: 

*/

#include "enum.h"
#include <iostream>
#include <vector>
#include <ctime>

void enumFunction(std::vector <int> vec, int size)
{
	int max = 0, newSum = 0, start = 0, end = 0;
	double time = 0;
	clock_t startClock, endClock;

	startClock = clock();
	for (int i = 0; i < size; i++)
	{
		newSum = 0;
		for (int j = i; j < size; j++)
		{
			for (i; i <= j; i++)
				newSum += vec[i];

			if (newSum > max)
			{
				start = i;
				end = j;
				max = newSum;
			}
		}
	}
	endClock = clock();

	time = ((double)(endClock - startClock)/CLOCKS_PER_SEC);
	std::cout << time << std::endl;
}