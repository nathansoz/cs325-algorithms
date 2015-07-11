#include <fstream>
#include <iostream>
#include <vector>

#include "../include/enum.h"
#include "../include/betterEnum.h"
#include "../include/linear.h"
#include "../include/Helper/fileUtils.h"
#include "../include/Helper/timingRoutines.h"

int main()
{
	std::ifstream test;
	test.open("/tmp/test.txt");
    std::ofstream out;
    out.open("/tmp/outLinear.txt");
	std::vector<std::vector<int>*>* processedInts = Helper::processMSSFile(test);

	std::cout << "Results of enumFunction: \n";
	for(int i = 0; i < processedInts->size(); i++)
	{
        int start;
        int end;
        int total = enumFunction(*(processedInts->at(i)), start, end);
        Helper::WriteResultsToFile(out, *processedInts->at(i), start, end, total);
        std::cout << '\n';
	}

	std::cout << "Results of betterEnumFunction: \n";
	for(int i = 0; i < processedInts->size(); i++)
	{
        int start;
        int end;
        int total = betterEnumFunction(*(processedInts->at(i)), start, end);
        Helper::WriteResultsToFile(out, *processedInts->at(i), start, end, total);
        std::cout << '\n';
	}
	std::cout << "Results of linear function: \n";
	for(int i = 0; i < processedInts->size(); i++)
	{
        int start;
        int end;
        int total = linear(*(processedInts->at(i)), start, end);
        Helper::WriteResultsToFile(out, *processedInts->at(i), start, end, total);
		std::cout << '\n';
	}
    out.close();


    std::vector<int>* randNums = Helper::GenRandNums(250);


    int(*funPtr1)(std::vector<int>) = &enumFunction;
    Helper::ClockMSSFunction(funPtr1, randNums);





	test.close();
	return 0;
}
