#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	vector<vector<string>> partition(string s)
	{
		int len = s.size();
		if (len == 0) return {};

		vector<vector<string>> ret;
		vector<string> pre;
		vector<vector<bool>> palin = vector<vector<bool>>(len, vector<bool>(len, false));

		// get palin
		palin[0][0] = true;
		for (int i = 1; i < len; i++)
		{
			palin[i][i] = palin[i][i - 1] = true;

			for (int j = 0; j < i; j++)
			{
				if (palin[j + 1][i - 1] && s[j] == s[i])
				{
					palin[j][i] = true;
				}
			}
		}

		dfs(ret, pre, palin, s, 0, len - 1);

		return ret;
	}

	void dfs(vector<vector<string>>& ret, vector<string>& pre, vector<vector<bool>>& palin, string& str, int idx, int last)
	{
		if (idx > last)
		{
			ret.push_back(pre);
			return;
		}

		for (int i = idx; i <= last; i++)
		{
			if (palin[idx][i])
			{
				pre.push_back(string(str, idx, i - idx + 1));
				dfs(ret, pre, palin, str, i + 1, last);
				pre.pop_back();
			}
		}
	}
};


int main()
{
	Solution solution;

	string input = "aab";

	solution.partition(input);

	while (getchar());

	return 0;
}