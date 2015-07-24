#include "../../include/Helper/timingRoutines.h"
#include <ctime>
#include <iostream>
#include <time.h>
#include <stdlib.h>


void Helper::ClockTimeFunction(int (*timeFun)(std::vector<int>&, int, std::vector<int>&), std::vector<int>& coins, int changeVal, std::vector<int> &ChangeCoinsUsed)
{
    std::clock_t start = std::clock();
    int result =timeFun(coins, changeVal, ChangeCoinsUsed);
    double total = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "N: " << coins.size() << " Result: " << result << " CPU Seconds: " << total << '\n';

}