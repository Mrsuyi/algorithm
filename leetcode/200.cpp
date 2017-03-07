#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	int numIslands(vector<vector<char>>& grid)
	{
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		int ret = 0;

		for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == '1')
			{
				ret++;
				dfs(grid, i, j, m, n);
			}
		}

		return ret;
	}

	void dfs(vector<vector<char>>& grid, int x, int y, int m, int n)
	{
		if (grid[x][y] == '0') return;

		grid[x][y] = '0';

		if (x > 0) dfs(grid, x - 1, y, m, n);
		if (x < m - 1) dfs(grid, x + 1, y, m, n);
		if (y > 0) dfs(grid, x, y - 1, m, n);
		if (y < n - 1) dfs(grid, x, y + 1, m, n);
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}