#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int l1 = word1.size();
		int l2 = word2.size();

		if (l1 == 0) return l2;
		if (l2 == 0) return l1;

		vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

		for (int i = 0; i <= l1; i++) dp[i][0] = i;
		for (int j = 0; j <= l2; j++) dp[0][j] = j;

		for (int i = 1; i <= l1; i++)
		for (int j = 1; j <= l2; j++)
		{
			int add = dp[i - 1][j] + 1;
			int del = dp[i][j - 1] + 1;
			int chg = dp[i - 1][j - 1] + (word2[j - 1] != word1[i - 1]);
			dp[i][j] = min(min(add, del), chg);
		}

		return dp[l1][l2];
	}
};

int main()
{
	while (getchar());

	return 0;
}