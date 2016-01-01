#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 1d-dp
class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
		if (l1 + l2 != l3) return false;
		if (l3 == 0) return true;

		vector<bool> dp(l1 + 2, false);
		dp[1] = true;

		for (int i = 1; i <= l3; i++)
		{
			vector<bool> tmp(l1 + 2, false);

			int bgn = max(0, i - l2);
			int end = min(l1, i);
			bool flg = false;

			for (int j = bgn; j <= end; j++)
			{
				tmp[j + 1] = (dp[j] && s1[j - 1] == s3[i - 1]) || (dp[j + 1] && s2[i - j - 1] == s3[i - 1]);
				flg |= tmp[j + 1];
			}

			if (!flg) return false;
			dp = tmp;
		}

		return dp[l1 + 1];
	}
};

// 2d-dp
class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
		if (l1 + l2 != l3) return false;
		if (l3 == 0) return true;

		vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
		dp[0][0] = true;

		for (int i = 1; i <= l3; i++)
		{
			int bgn = max(0, i - l2 - 1), end = min(i - 1, l1);
			bool flg = false;
			for (int m = bgn, n = i - m - 1; m <= end; m++, n--)
			{
				if (dp[m][n])
				{
					if (m < l1 && s1[m] == s3[i - 1]) flg = dp[m + 1][n] = true;
					if (n < l2 && s2[n] == s3[i - 1]) flg = dp[m][n + 1] = true;
				}
			}
			if (!flg) return false;
		}

		return dp[l1][l2];
	}
};

int main()
{
	while (getchar());

	return 0;
}