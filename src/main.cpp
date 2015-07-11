#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>

#include "../include/enum.h"
#include "../include/betterEnum.h"
#include "../include/linear.h"
#include "../include/Helper/fileUtils.h"
#include "../include/Helper/timingRoutines.h"

int main()
{
	std::ifstream input;
	input.open("MSS_TestProblems.txt");
    if(!input.is_open())
    {
        input.close();
        std::cout << "MSS_TestProblems.txt not found in current directory. Now exiting." << std::endl;
        exit(1);
    }

    std::ofstream out;
    out.open("MSS_TestResults.txt");

	std::vector<std::vector<int>*>* processedInts = Helper::processMSSFile(input);
    input.close();

	out << "Results of enumFunction: \n";
	for(uint i = 0; i < processedInts->size(); i++)
	{
        int start;
        int end;
        int total = enumFunction(*(processedInts->at(i)), start, end);
        Helper::WriteResultsToFile(out, *processedInts->at(i), start, end, total);
        std::cout << '\n';
	}

	out << "Results of betterEnumFunction: \n";
	for(uint i = 0; i < processedInts->size(); i++)
	{
        int start;
        int end;
        int total = betterEnumFunction(*(processedInts->at(i)), start, end);
        Helper::WriteResultsToFile(out, *processedInts->at(i), start, end, total);
        std::cout << '\n';
	}
	out << "Results of linear function: \n";
	for(uint i = 0; i < processedInts->size(); i++)
	{
        int start;
        int end;
        int total = linear(*(processedInts->at(i)), start, end);
        Helper::WriteResultsToFile(out, *processedInts->at(i), start, end, total);
		std::cout << '\n';
	}
    out.close();

    std::cout << "Running timing function for enumFunction: " << std::endl;
    int enumValsN[] = {1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800};

    for(int i = 0; i < 10; i++)
    {
        std::vector<int>* randNums = Helper::GenRandNums(enumValsN[i]);
        int(*funPtr1)(std::vector<int>) = &enumFunction;
        Helper::ClockMSSFunction(funPtr1, randNums);
    }


	return 0;
}
