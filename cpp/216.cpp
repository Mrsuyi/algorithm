#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<vector<int>> ret;
		vector<int> prefix;

		dfs(ret, prefix, 0, k, n);

		return ret;
	}

	void dfs(vector<vector<int>>& ret, vector<int>& prefix, int last, int cnt, int val)
	{
		if (cnt == 1)
		{
			if (val < 10)
			{
				prefix.push_back(val);
				ret.push_back(prefix);
				prefix.pop_back();
			}
			return;
		}

		for (int i = last + 1; i < 10; i++)
		{
			int rest = val - i;
			if (rest <= i) break;

			prefix.push_back(i);
			dfs(ret, prefix, i, cnt - 1, rest);
			prefix.pop_back();
		}
	}
};

int main()
{
	Solution solution;

	solution.combinationSum3(3, 7);

	while (getchar());

	return 0;
}