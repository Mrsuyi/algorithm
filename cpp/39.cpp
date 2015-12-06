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
	vector<vector<int>> ret;
	vector<int> choose;

	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());

		choose.push_back(candidates[0]);
		for (int i = 1; i < candidates.size(); i++)
		{
			if (candidates[i] == candidates[i - 1]) continue;
			choose.push_back(candidates[i]);
		}

		vector<int> prefix;
		search(prefix, target, 0);

		return ret;
	}

	void search(vector<int> &prefix, int target, int offset)
	{
		for (int i = offset; i < choose.size(); i++)
		{
			if (choose[i] == target)
			{
				prefix.push_back(choose[i]);
				ret.push_back(vector<int>(prefix.begin(), prefix.end()));
				prefix.pop_back();
				return;
			}
			if (choose[i] < target)
			{
				prefix.push_back(choose[i]);
				search(prefix, target - choose[i], i);
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