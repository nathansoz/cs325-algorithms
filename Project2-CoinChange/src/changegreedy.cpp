#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "../include/changegreedy.h"

int greedyCoin(std::vector<int> &coins, int changeVal, std::vector<int> &returnCoinCount)
{
	int sum = 0;
	//Doesn't work in gcc
	//std::vector <int> returnCoinCount(coins.size(), 0);

	for(uint i = 0; i < coins.size(); i++)
		returnCoinCount.push_back(0);

	while (changeVal > 0)
	{
		for (long i = coins.size() - 1; i >= 0; i--)
		{
			int change = 0;

			while (changeVal >= coins[i])
			{
				change++;
				changeVal -= coins[i];
			}

			returnCoinCount.at(i) = change;
		}
	}

	for (uint j = 0; j < returnCoinCount.size(); j++)
		sum += returnCoinCount[j];

	return sum;
}