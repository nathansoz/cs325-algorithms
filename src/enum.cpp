/**********************************************************************
File: enum.cpp

Description: 

**************************************************************************/

#include "../include/enum.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

/***************************************************************************
Function: runEnum

Description: Calculates the sum of an array by looping over indices i
and j. Also calculates runtime of the function.

Parameters: vector of integers, size of vector

Pre-Conditions:
****************************************************************************/
void runEnum(std::ifstream &file, std::vector <int> vec)
{

}

/***************************************************************************
Function: enumFunction

Description: Calculates the sum of an array by looping over indices i
and j. Also calculates runtime of the function.

Parameters: vector of integers, size of vector

Pre-Conditions: 
****************************************************************************/

int enumFunction(std::vector <int> vec, int size)
{
	int max = 0, newSum = 0, start = 0, end = 0;

	/*Iterate through array*/
	for (int i = 0; i < size; i++)
	{
		/*Reset newSum*/
		newSum = 0;

		/*Go through array from i onward*/
		for (int j = i; j < size; j++)
		{
			/*Calculate newSum*/
			for (i; i <= j; i++)
				newSum += vec[i];

			/*If we have a new max sum*/
			if (newSum > max)
			{
				start = i;
				end = j;
				max = newSum;
			}
		}
	}

	return max;
}