#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict)
	{
		int len = s.size();

		vector<bool> breaks(len + 1, false);
		breaks[0] = true;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (breaks[j] && wordDict.find(s.substr(j, i - j + 1)) != wordDict.end())
				{
					breaks[i + 1] = true;
					break;
				}
			}
		}
		if (!breaks[len]) return {};

		vector<int> idxs;
		for (int i = 0; i <= len; i++)
		{
			if (breaks[i])
			{
				idxs.push_back(i);
			}
		}

		len = idxs.size();
		vector<vector<string>> dp(len + 1);
		dp[0] = {""};
		for (int i = 1; i <= len; i++)
		{
			for (int j = 0; j < i; j++)
			{
				string sub = s.substr(idxs[j], idxs[i] - idxs[j]);
				if (wordDict.find(sub) != wordDict.end())
				{
					for (auto& str : dp[j])
					{
						dp[i].push_back(str + sub + ' ');
					}
				}
			}
		}

		for (auto& str : dp[len])
		{
			str.pop_back();
		}
		return dp[len];
	}
};

int main()
{
	while (getchar());

	return 0;
}