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
	int choice;

	/*Using test problems for now
	Need random large arrays for questions*/
	file.open("MSS_TestProblems.txt");
	outFile.open("results.txt");

	if (file.is_open())
	{
		do
		{
			/*MENU*/
			std::cout << "Please choose from the following options:\n\n"
				<< "1. Run Enumeration Algorithm\n"
				<< "2. Run Better Enumeration Algorithm\n"
				<< "3. Run 3rd Algo\n" //will update
				<< "4. Run 4th Algo\n" //will update
				<< "5. Quit\n\n"
				<< "Enter your choice: ";
			std::cin >> choice;

			switch (choice)
			{
			case 1: 
			}


			while (!file.eof())
			{
				std::getline(file, str);
				arrToTest = getRidOfCrap(str);
				enumFunction(arrToTest, arrToTest.size());
			}
		} while (choice != 5);
	}
	else
		std::cout << "Error!\n";

	file.close();
	outFile.close();


	return 0;
}