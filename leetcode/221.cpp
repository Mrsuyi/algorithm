#include <iostream>
#include <vector>
#include <stack>
#include <string>
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
	int maximalSquare(vector<vector<char>>& matrix)
	{
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();

		int max = 0;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '1')
			{
				int len = min(dp[i][j + 1], min(dp[i + 1][j], dp[i][j])) + 1;
				dp[i + 1][j + 1] = len;
				if (len > max) max = len;
			}
		}

		return max * max;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}