#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>	

using namespace std;

// backtrack
class Solution
{
public:
	bool isMatch(string s, string p)
	{
		int ls = s.length();
		int lp = p.length();
	
		int is(0), ip(0), js(-1), jp(-1);
		while (is < ls)
		{
			if (ip < lp && (p[ip] == s[is] || p[ip] == '?'))
			{
				is++;
				ip++;
			}
			else if (ip < lp && p[ip] == '*')
			{
				js = is;
				jp = ++ip;

				if (ip == lp) return true;
			}
			else if (js != -1)
			{
				is = ++js;
				ip = jp;
			}
			else
			{
				return false;
			}
		}
		while (ip < lp && p[ip] == '*') ip++;

		return ip == lp;
	}
};

// dp
class Solution
{
public:
	bool isMatch(string s, string p)
	{
		int ls = s.length();
		int lp = p.length();

		vector<vector<bool>> dp(ls + 1, vector<bool>(lp + 1, false));
		dp[0][0] = true;
		
		for (int i = 0; i <= ls; i++)
		for (int j = 1; j <= lp; j++)
		{
			if (p[j - 1] == '?')
			{
				dp[i][j] = i > 0 && dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*')
			{
				dp[i][j] = dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = i > 0 && dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
			}
		}

		return dp[ls][lp];
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}