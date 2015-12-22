#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		int m = s.length();
		int n = p.length();
		
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;

		for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (p[j - 1] == '.')
			{
				dp[i][j] = i > 0 && dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*')
			{
				dp[i][j] = dp[i][j - 1] || dp[i][j - 2] ||
					       (i > 0 && dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
			}
			else
			{
				dp[i][j] = i > 0 && dp[i - 1][j - 1] && p[j - 1] == s[i - 1];
			}
		}
		return dp[m][n];
	}
};

int main()
{
	while (getchar());

	return 0;
}