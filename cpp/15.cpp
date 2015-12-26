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
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		int len = nums.size();
		sort(nums.begin(), nums.end());

		vector<vector<int>> ret;
		for (int i = 0; i < len - 2;)
		{
			for (int j = i + 1; j < len - 1;)
			{
				int rest = 0 - nums[i] - nums[j];
				if (rest < nums[j]) break;
				if (search(nums, j + 1, len - 1, rest))
				{
					ret.push_back({ nums[i], nums[j], rest });
				}
				while (nums[++j] == nums[j - 1]) {}
			}
			while (nums[++i] == nums[i - 1]) {}
		}
		return ret;
	}

	bool search(vector<int>& nums, int l, int r, int target)
	{
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (nums[mid] == target)
			{
				return true;
			}
			else if (nums[mid] > target)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
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