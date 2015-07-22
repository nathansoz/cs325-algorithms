#include <vector>
#include <limits.h>
#include <iostream>

struct changeSet{
	int amount;
	std::vector<int> coinsUsed;
};

int changeslow(std::vector<int> coins, int changeVal, std::vector<int> &ChangeCoinsUsed);

void bruteChange(int changeVal, std::vector<int> coins, changeSet &bestSet, changeSet curSet);