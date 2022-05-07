#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	vector<int> nums;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf(" %d", &num);
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	int medianIndex = int(floor((nums.size() + 1) / 2)) - 1;
	int calCnt = 1;
	for (int i = 0; i <= medianIndex; i++)
	{
		while (nums[i] != 1)
		{
			nums[i] = int(floor(nums[i] / 2));
			calCnt++;
		}
	}
	cout << calCnt;
	return 0;
}