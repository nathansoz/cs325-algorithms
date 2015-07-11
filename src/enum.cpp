/**********************************************************************
File: enum.cpp

Description: 

**************************************************************************/

#include "enum.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

/***************************************************************************
Function: enumFunction

Description: Calculates the sum of an array by looping over indices i
and j. Also calculates runtime of the function.

Parameters: vector of integers, size of vector

Pre-Conditions: 
****************************************************************************/

int enumFunction(std::vector <int> vec, int size)
{
	int max = 0, newSum = 0;

	/*Iterate through array*/
	for (int i = 0; i < vec.size(); i++)
	{
		/*Go through array from i onward*/
		for (int j = i; j < vec.size(); j++)
		{
			/*Reset newSum*/
			newSum = 0;

			/*Calculate newSum*/
			for (int k = i; k <= j; k++)
				newSum += vec[k];

			/*If we have a new max sum*/
			if (newSum > max)
				max = newSum;
		}
	}

	return max;
}