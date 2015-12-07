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
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> ret;
		vector<bool> chosen = vector<bool>(nums.size(), false);
		vector<int> prefix;
		
		search(prefix, nums, chosen, ret);

		return ret;
	}

	void search(vector<int>& prefix, vector<int>& nums, vector<bool>& chosen, vector<vector<int>>& ret)
	{
		if (prefix.size() == nums.size() - 1)
		{
			int i = 0;
			while (chosen[i]) { i++; }
			ret.push_back(vector<int>(prefix));
			ret.back().push_back(nums[i]);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (!chosen[i])
			{
				chosen[i] = true;
				prefix.push_back(nums[i]);
				search(prefix, nums, chosen, ret);
				prefix.pop_back();
				chosen[i] = false;
			}
		}
	}
};

int main()
{
	Solution solution;

	vector<int> input = { 1, 2, 4, 4 };
	solution.permute(input);

	while (getchar());

	return 0;
}