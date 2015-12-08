#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
private:
	inline int min(const int a, const int b) { return a < b ? a : b; };
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();

		int** dp = new int*[m + 1];
		for (int i = 0; i <= m; i++)
		{
			dp[i] = new int[n + 1];
			dp[i][0] = INT_MAX;
		}
		fill_n(dp[0], n + 1, INT_MAX);
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