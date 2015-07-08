/******************************************************
Program: Project 1
Course: CS 325-400 Su 15
Authors:

File: main.cpp
Description: 





********************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "enum.h"
#include "betterEnum.h"

std::vector <int> getRidOfCrap(std::string &tempString)
{
	char tempCh[1000];
	std::vector <int> vec;
	int count = 0;

	for (std::string::iterator it = tempString.begin(); it != tempString.end(); it++)
	{
		if (*it != '[' && *it != ']' && *it != ' ')
		{
			if (*it == ',')
			{
				vec.push_back(atoi(tempCh));
				strcpy_s(tempCh, "");
				count = 0;
			}
			else
			{
				tempCh[count] = *it;
				count++;
			}
		}
	}

	return vec;
}

int main()
{
	std::ifstream file;

	std::ofstream outFile;
	clock_t start, end;
	double clockTime;
	std::vector <int> arrToTest;
	std::string str;

	file.open("MSS_TestProblems.txt");
	outFile.open("results.txt");

	if (file.is_open())
	{
		while (!file.eof())
		{
			std::getline(file, str);
			arrToTest = getRidOfCrap(str);
			enumFunction(arrToTest, arrToTest.size());
		}
	}
	else
		std::cout << "Error!\n";


	return 0;
}