#include "../../include/Helper/timingRoutines.h"
#include <ctime>
#include <iostream>
#include <time.h>
#include <stdlib.h>



std::vector<int>* Helper::GenRandNums(int numberOfInts)
{
    srand(time(NULL));
    std::vector<int>* randNums = new std::vector<int>();

    for(int i = 0; i < numberOfInts; i++)
    {
        // generate numbers -100 - 100
        int num = (rand() % 201) - 100;
        randNums->push_back(num);
    }

    return randNums;
}

void Helper::ClockMSSFunction(int (*timeFun)(std::vector<int>), std::vector<int>* numbers)
{
    std::clock_t start = std::clock();
    int result =timeFun(*numbers);
    std::clock_t total = std::clock() - start;
    std::cout << "Result: " << result << " Total clocks: " << total << '\n';

}

void Helper::ClockMSSFunction(int (*timeFun)(std::vector<int>, int), std::vector<int>* numbers, int numInts)
{
    std::clock_t start = std::clock();
    int result = timeFun(*numbers, numInts);
    std::clock_t total = std::clock() - start;
    std::cout << "N: " << numInts << " Result: " << result << " Total clocks: " << total << '\n';

}