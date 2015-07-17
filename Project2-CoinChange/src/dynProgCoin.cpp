#include <limits.h>
#include <iostream>
#include "../include/dynProgCoin.h"

int dynProgCoin(std::vector<int> coins, int changeVal)
{
    int **coinCount = new int*[changeVal + 1];
    int *results = new int[changeVal + 1];
    results[0] = 0;
    results[1] = 1;

    for(int i = 0; i < changeVal + 1; i++)
    {
        coinCount[i] = new int[coins.size()];
        for(int j = 0; j < coins.size(); j++)
            coinCount[i][j] = 0;
    }


    for(int i = 2; i <= changeVal; i++)
    {
        int lastCoinIndex = -1;
        int min = INT_MAX;
        int maxJ = -1;

        for(int j = 0; j < coins.size(); j++)
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
                         coinCount[i][j - lastCoinIndex]--;
                         coinCount[i][j]++;
                         lastCoinIndex = j;
                     }
                 }
            }
        }
        results[i] = min;
    }

    for(int i = 0; i < coins.size(); i++)
        std::cout << coinCount[changeVal][i] << '\n';

    return results[changeVal];
}
