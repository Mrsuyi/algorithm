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
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int dp[101][101];
		memset(dp, 0, sizeof(dp));
		dp[0][1] = 1;

		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		
		for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			if (obstacleGrid[i - 1][j - 1])
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
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