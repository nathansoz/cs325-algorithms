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
	std::vector<std::vector<int>*>* processedInts = Helper::processMSSFile(test);

	std::cout << "Results of enumFunction: \n";
	for(int i = 0; i < processedInts->size(); i++)
	{
		std::cout << enumFunction(*(processedInts->at(i)), processedInts->at(i)->size());
		std::cout << '\n';
	}

	std::cout << "Results of betterEnumFunction: \n";
	for(int i = 0; i < processedInts->size(); i++)
	{
		std::cout << betterEnumFunction(*(processedInts->at(i)), processedInts->at(i)->size());
		std::cout << '\n';
	}

	std::cout << "Results of linear function: \n";
	for(int i = 0; i < processedInts->size(); i++)
	{
		std::cout << linear(*(processedInts->at(i)));
		std::cout << '\n';
	}


    std::vector<int>* randNums = Helper::GenRandNums(250);


    int(*funPtr1)(std::vector<int>, int) = &enumFunction;
    Helper::ClockMSSFunction(funPtr1, randNums, 10000);





	test.close();
	return 0;
}
