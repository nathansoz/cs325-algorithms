#pragma once
#include <vector>

namespace Helper
{
    void ClockTimeFunction(int (*timeFun)(std::vector<int>&, int, std::vector<int>&), std::vector<int> &coins, int changeVal, std::vector<int> &ChangeCoinsUsed);
}