#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	int lengthOfLIS(vector<int>& nums)
	{
		vector<int> v;

		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			auto n = lower_bound(v.begin(), v.end(), nums[i]);

			if (n == v.end())
			{
				v.push_back(nums[i]);
			}
			else
			{
				*n = nums[i];
			}
		}

		return v.size();
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}