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

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());

		vector<int> prefix;
		search(candidates, prefix, target, 0, INT_MIN);

		return ret;
	}

	void search(vector<int> &choose, vector<int> &prefix, int target, int offset, int last_index)
	{
		for (int i = offset; i < choose.size(); i++)
		{
			// if [a] == [a+1], there must exist a previous case where [a] is chosen and [a+1] is not
			// if you choose [a+1] this time, these two case are equal
			if (i != 0 && choose[i] == choose[i - 1])
			{
				if (last_index != i - 1) continue;
			}

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
				search(choose, prefix, target - choose[i], i + 1, i);
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