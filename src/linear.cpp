#include <vector>
#include <algorithm> // For std::max

#include "../include/linear.h"

int linear(std::vector<int> array)
{
	int maxToPoint = 0;
	int maxToReturn = 0;

        for(int i = 0; i < array.size(); i++)
	{
		maxToPoint = std::max(0, maxToPoint + array[i]);
		maxToReturn = std::max(maxToPoint, maxToReturn);
	}

        return maxToReturn;
}
