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
	void merge(vector<vector<int>>& src, vector<vector<int>>& dst, int add, int limit)
	{
		for (auto v : src)
		{
			if (v.size() < limit)
			{
				vector<int> m = vector<int>(v);
				m.push_back(add);
				dst.push_back(m);
			}
		}
	}

	vector<string> restoreIpAddresses(string s)
	{
		int len = s.length();

		if (len < 4 || len > 12) return {};

		vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(len + 1, vector<vector<int>>());

		dp[len].push_back({});
		dp[len - 1].push_back({ s[len - 1] - '0' });
		dp[len - 2].push_back({ s[len - 1] - '0', s[len - 2] - '0' });

		if (s[len - 2] != '0')
		{
			dp[len - 2].push_back({ (s[len - 2] - '0') * 10 + s[len - 1] - '0' });
		}

		for (int i = len - 3; i >= 0; i--)
		{
			int limit = i == 0 ? 4 : 3;

			int n1 = (s[i] - '0');
			int n2 = (s[i] - '0') * 10 + (s[i + 1] - '0');
			int n3 = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');

			if (n1 == 0)
			{
				merge(dp[i + 1], dp[i], n1, limit);
			}
			else if (n3 > 255)
			{
				merge(dp[i + 1], dp[i], n1, limit);
				merge(dp[i + 2], dp[i], n2, limit);
			}
			else
			{
				merge(dp[i + 1], dp[i], n1, limit);
				merge(dp[i + 2], dp[i], n2, limit);
				merge(dp[i + 3], dp[i], n3, limit);
			}
		}

		vector<string> ret;
		for (auto v : dp[0])
		{
			if (v.size() == 4)
			{
				ret.push_back({ to_string(v[3]) + "."
							  + to_string(v[2]) + "."
							  + to_string(v[1]) + "."
							  + to_string(v[0])});
			}
		}
		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}