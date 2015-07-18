#include <iostream>
#include <vector>

#include "../include/dynProgCoin.h"

int main()
{
    std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(5);

    int test1 = 10;

    std::vector<int> ret;

    int test2 = dynProgCoin(test, test1, ret);

    std::cout << test2 << '\n';
}