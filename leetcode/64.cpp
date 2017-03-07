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
	int minPathSum(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> dp(m + 1, vector<int>(n + 1));

		fill(dp[0].begin(), dp[0].end(), INT_MAX);
		for (auto& v : dp)
		{
			v[0] = INT_MAX;
		}
		dp[0][1] = 0;

		for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
		}

		return dp[m][n];
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}