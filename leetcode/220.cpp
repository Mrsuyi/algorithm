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
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		int size = nums.size();
		set<long long> set;

		for (int i = 0, j = 0; i < size; i++)
		{
			if (i - j > k)
			{
				set.erase(nums[j++]);
			}

			auto find = set.lower_bound(nums[i] - t);
			if (find != set.end() && *find - nums[i] <= t)
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
	Solution solution;

	while (getchar());

	return 0;
}