#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int max = INT_MIN;

		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if (sum > max)
			{
				max = sum;
			}
			if (sum < 0)
			{
				sum = 0;
			}
		}

		return max;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}