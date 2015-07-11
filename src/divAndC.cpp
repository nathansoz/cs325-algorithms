#include "divAndC.h"

int divAndC(std::vector <int> vec)
{
	int start = 0;
	int end = vec.size() - 1;
	return findMax(vec, start, end);
}

int divAndC(std::vector <int> vec, int &start, int &end)
{
	return findMax(vec, start, end);
}

int findMax(std::vector <int> vec, int &start, int &end)
{
	if (start == end)
	{
		return vec[start];
	}

	int mid = (start + end) / 2;
	int rightStart = mid + 1;

	return std::max(std::max(findMax(vec, start, mid), findMax(vec, rightStart, end)), maxCrossing(vec, start, end, mid));

}

int maxCrossing(std::vector<int> vec, int crossStart, int crossEnd, int mid)
{
	//find max sum left half
	int leftMax = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= crossStart; i--)
	{
		sum += vec[i];
		if (sum > leftMax)
		{
			leftMax = sum;
		}
	}

	//find max sum right half
	int rightMax = INT_MIN;
	sum = 0;
	for (int j = mid + 1; j <= crossEnd; j++)
	{
		sum += vec[j];
		if (sum > rightMax)
		{
			rightMax = sum;
		}
	}

	return leftMax + rightMax;
}