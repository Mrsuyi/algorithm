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
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> ret;
		vector<int> prefix;
		sort(candidates.begin(), candidates.end());
		search(ret, candidates, prefix, target, 0);
		return ret;
	}

	void search(vector<vector<int>>& ret, vector<int>& nums, vector<int> &prefix, int target, int offset)
	{
		if (target == 0)
		{
			ret.push_back(prefix);
			return;
		}
		for (int i = offset; i < nums.size(); i++)
		{
			if (nums[i] <= target)
			{
				prefix.push_back(nums[i]);
				search(ret, nums, prefix, target - nums[i], i);
				prefix.pop_back();
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