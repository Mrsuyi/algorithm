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
	int cnt(unsigned i)
	{
		int ret = 0;
		while (i)
		{
			ret++;
			i &= i - 1;
		}
		return ret;
	}

	vector<string> restoreIpAddresses(string s)
	{
		vector<vector<unsigned>> dp(3, { 0 });

		for (int i = 0; i < s.size(); i++)
		{
			vector<unsigned> tmp;

			int n = s[i] - '0';
			for (auto n : dp[0])
			{
				if (cnt(n) < 4)
				{
					tmp.push_back(n | (1 << i));
				}
			}

			if (i > 0)
			{
				n += 10 * (s[i - 1] - '0');
				if (n >= 10)
				{
					for (auto n : dp[1])
					{
						if (cnt(n) < 4)
						{
							tmp.push_back(n | (1 << i));
						}
					}
				}
			}

			if (i > 1)
			{
				n += 100 * (s[i - 2] - '0');
				if (n >= 100 && n <= 255)
				{
					for (auto n : dp[2])
					{
						if (cnt(n) < 4)
						{
							tmp.push_back(n | (1 << i));
						}
					}
				}
			}

			swap(dp[2], dp[1]);
			swap(dp[1], dp[0]);
			dp[0] = tmp;
		}

		vector<string> ret;
		for (auto n : dp[0])
		{
			if (cnt(n) == 4)
			{
				string str(s.size() + 4, 0);
				for (int i = 0, j = 0; i < s.size(); i++, j++)
				{
					str[j] = s[i];
					if (n & (1 << i))
					{
						str[++j] = '.';
					}
				}
				str.pop_back();
				ret.push_back(str);
			}
		}
		return ret;
	}
};

int main()
{
	Solution solution;

	solution.restoreIpAddresses("25525511135");

	while (getchar());

	return 0;
}