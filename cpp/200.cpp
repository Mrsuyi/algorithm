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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
	class Pos
	{
	public:
		int row, col;
		Pos(int row, int col) : row(row), col(col) {}
	};

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
				bfs(grid, Pos(i, j), m, n);
			}
		}

		return ret;
	}

	void bfs(vector<vector<char>>& grid, Pos pos, int m, int n)
	{
		queue<Pos> q;
		q.push(pos);

		while (!q.empty())
		{
			Pos p = q.front();
			q.pop();

			int row = p.row;
			int col = p.col;

			if (grid[row][col] == '1')
			{
				int _row = row - 1;
				int row_ = row + 1;
				int _col = col - 1;
				int col_ = col + 1;

				if (_row >= 0 && grid[_row][col] == '1') q.push(Pos(_row, col));
				if (row_ <  m && grid[row_][col] == '1') q.push(Pos(row_, col));
				if (_col >= 0 && grid[row][_col] == '1') q.push(Pos(row, _col));
				if (col_ <  n && grid[row][col_] == '1') q.push(Pos(row, col_));

				grid[row][col] = '0';
			}
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}