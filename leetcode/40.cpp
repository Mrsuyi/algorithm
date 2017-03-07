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
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		vector<vector<int>> ret;
		vector<int> dfs;
		sort(candidates.begin(), candidates.end());
		search(ret, candidates, dfs, target, 0, INT_MIN);
		return ret;
	}

	void search(vector<vector<int>>& ret, vector<int> &nums, vector<int> &dfs, int target, int offset, int lst)
	{
		if (target == 0)
		{
			ret.push_back(dfs);
			return;
		}
		for (int i = offset; i < nums.size(); i++)
		{
			if (i != 0 && nums[i] == nums[i - 1])
			{
				if (lst != i - 1) continue;
			}
			if (nums[i] <= target)
			{
				dfs.push_back(nums[i]);
				search(ret, nums, dfs, target - nums[i], i + 1, i);
				dfs.pop_back();
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