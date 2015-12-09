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
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());

		vector<vector<int>> ret;
		vector<int> prefix;

		dfs(ret, prefix, nums, 0, -1);

		return ret;
	}

	void dfs(vector<vector<int>>& ret, vector<int>& prefix, vector<int>& nums, int idx, int last)
	{
		if (idx == nums.size())
		{
			ret.push_back(prefix);
			return;
		}
		else
		{
			// not choose
			dfs(ret, prefix, nums, idx + 1, last);

			// choose
			if (idx != 0 && nums[idx] == nums[idx - 1] && last != idx - 1) return;

			prefix.push_back(nums[idx]);
			dfs(ret, prefix, nums, idx + 1, idx);
			prefix.pop_back();
		}
	}
};

int main()
{
	Solution solution;

	vector<int> input = { 1, 2, 2 };
	solution.subsetsWithDup(input);

	while (getchar());

	return 0;
}