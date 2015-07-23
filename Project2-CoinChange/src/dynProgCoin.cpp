#include <limits.h>
#include <iostream>
#include "../include/dynProgCoin.h"

int dynProgCoin(std::vector<int> &coins, int changeVal, std::vector<int> &returnCoinCount)
{
    int **coinCount = new int*[changeVal + 1];
    int *results = new int[changeVal + 1];
    results[0] = 0;
    results[1] = 1;

    for(int i = 0; i < changeVal + 1; i++)
    {
        coinCount[i] = new int[coins.size()];
        for(uint j = 0; j < coins.size(); j++)
            coinCount[i][j] = 0;
    }

    //create needed base coinCount
    coinCount[1][0] = 1;


    for(int i = 2; i <= changeVal; i++)
    {
        int lastCoinIndex = -1;
        int min = INT_MAX;
        int maxJ = -1;

        for(uint j = 0; j < coins.size(); j++)
        {
            if(coins.at(j) <= i)
            {
                 int current;
                 current = 1 + results[i - coins.at(j)];

                 if(current < min)
                 {
                     min = current;
                     maxJ = j;

                     if(lastCoinIndex == -1)
                     {
                         lastCoinIndex = j;
                         coinCount[i][j]++;
                     }
                     else
                     {
                         coinCount[i][lastCoinIndex]--;
                         coinCount[i][j]++;
                         lastCoinIndex = j;
                     }
                 }
            }
        }

        for(uint j = 0; j < coins.size(); j++)
            coinCount[i][j] += coinCount[i - coins.at(maxJ)][j];

        results[i] = min;
    }

    for(uint i = 0; i < coins.size(); i++)
        returnCoinCount.push_back(coinCount[changeVal][i]);

    //Set the return value so that we can clean up the memory
    int retVal = results[changeVal];

    //Memory Cleanup section
    for(int i = 0; i < (changeVal + 1); i++)
    {
        delete[] coinCount[i];
    }
    delete[] coinCount;
    delete[] results;
    //End Cleanup

    return retVal;
}
