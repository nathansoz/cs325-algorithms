#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "changegreedy.h"

int greedyCoin(std::vector <int> &coins, int changeVal, std::vector <int> &returnCoinCount)
{
	int sum = 0;
	std::vector <int> returnCoinCount(coins.size(), 0);

	while (changeVal > 0)
	{
		for (int i = coins.size() - 1; i >= 0; i--)
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

	for (int j = 0; j < returnCoinCount.size(); j++)
		sum += returnCoinCount[j];

	return sum;
}