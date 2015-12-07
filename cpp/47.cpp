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
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<pair<int, int>> cnt;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
		{
			if (i != 0 && nums[i] == nums[i - 1])
			{
				cnt.back().second++;
			}
			else
			{
				cnt.push_back(make_pair(nums[i], 1));
			}
		}

		vector<vector<int>> ret;
		vector<int> prefix;
		search(prefix, cnt, nums.size(), ret);

		return ret;
	}

	void search(vector<int>& prefix, vector<pair<int, int>>& nums, int remain, vector<vector<int>>& ret)
	{
		if (remain == 1)
		{
			for (auto& num : nums)
			{
				if (num.second)
				{
					ret.push_back(vector<int>(prefix));
					ret.back().push_back(num.first);
					return;
				}
			}
		}

		for (auto& num : nums)
		{
			if (num.second)
			{
				num.second--;
				prefix.push_back(num.first);
				search(prefix, nums, remain - 1, ret);
				prefix.pop_back();
				num.second++;
			}
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}