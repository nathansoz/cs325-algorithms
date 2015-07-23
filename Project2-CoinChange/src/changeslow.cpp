#include "../include/changeslow.h"

int changeslow(std::vector<int> coins, int changeVal, std::vector<int> &ChangeCoinsUsed)
{
	changeSet bestSet;
	for (uint i = 0; i < coins.size(); i++)
	{
		bestSet.coinsUsed.push_back(0);
	}
	bestSet.amount = INT_MAX;

	changeSet curSet;
	for (uint i = 0; i < coins.size(); i++)
	{
		curSet.coinsUsed.push_back(0);
	}
	curSet.amount = 0;


	bruteChange(changeVal, coins, bestSet, curSet);

	for (uint i = 0; i < coins.size(); i++)
	{
		ChangeCoinsUsed.push_back(bestSet.coinsUsed[i]);
	}

	return bestSet.amount;

}

void bruteChange(int changeVal, std::vector<int> coins, changeSet &bestSet, changeSet curSet)
{

	if (changeVal == 0)
	{
		if (curSet.amount < bestSet.amount)
		{
			bestSet.amount = curSet.amount;
			bestSet.coinsUsed = curSet.coinsUsed;
		}
		return;
	}

	if (curSet.amount > bestSet.amount)
	{
		return;
	}

	for (int i = coins.size() - 1; i >= 0; i--)
	{
		if (changeVal >= coins[i])
		{
			changeSet newSet;
			newSet.amount = curSet.amount + 1;
			newSet.coinsUsed = curSet.coinsUsed;
			newSet.coinsUsed[i]++;
			bruteChange(changeVal - coins[i], coins, bestSet, newSet);
		}
	}
}

