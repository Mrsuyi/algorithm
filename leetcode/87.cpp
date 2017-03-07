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
	bool isScramble(string s1, string s2)
	{
		int len = s1.size();
		if (len == 0) return false;

		vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(len + 1)));

		for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			dp[i][j][1] = s1[i] == s2[j];
		}
		
		for (int l = 2; l <= len; l++)
		for (int i = 0; i < len - l + 1; i++)
		for (int j = 0; j < len - l + 1; j++)
		for (int k = 1; k < l; k++)
		{
			if ((dp[i][j][k] && dp[i + k][j + k][l - k])
			 || (dp[i][j + k][l - k] && dp[i + l - k][j][k]))
			{
				dp[i][j][l] = true;
				break;
			}
		}

		return dp[0][0][len];
	}
};

int main()
{
	Solution solution;
	solution.isScramble("great", "rgtae");

	while (getchar());

	return 0;
}