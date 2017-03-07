#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		int len = nums.size();
		unordered_set<int> set;

		for (int i = 0; i < len; i++)
		{
			if (i > k)
			{
				set.erase(nums[i - k - 1]);
			}
			if (set.count(nums[i]))
			{
				return true;
			}
			set.insert(nums[i]);
		}

		return false;
	}
};

int main()
{
	while (getchar());

	return 0;
}