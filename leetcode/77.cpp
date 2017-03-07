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
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> ret;
		vector<int> prefix;
		dfs(ret, prefix, 1, n, k);
		return ret;
	}

	void dfs(vector<vector<int>>& ret, vector<int>& prefix, int idx, int max, int cnt)
	{
		if (cnt == 0)
		{
			ret.push_back(vector<int>(prefix));
		}
		else
		{
			for (int i = idx; i <= max - cnt + 1; i++)
			{
				prefix.push_back(i);
				dfs(ret, prefix, i + 1, max, cnt - 1);
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