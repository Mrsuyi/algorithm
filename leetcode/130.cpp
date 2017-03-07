#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
private:
	struct Pt
	{
		int row, col;
		Pt(int a, int b) : row(a), col(b) {}
	};

public:
	void solve(vector<vector<char>>& board)
	{
		int m = board.size();
		if (m < 2) return;
		int n = board[0].size();
		if (n < 2) return;

		queue<Pt> pts;

		for (int i = 0; i < m; i++)
		{
			pts.push(Pt(i, 0));
			pts.push(Pt(i, n - 1));
		}
		for (int j = 0; j < n; j++)
		{
			pts.push(Pt(0, j));
			pts.push(Pt(m - 1, j));
		}

		bfs(board, pts, m, n);

		for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '#')
			{
				board[i][j] = 'O';
			}
			else if (board[i][j] == 'O')
			{
				board[i][j] = 'X';
			}
		}
	}

	void bfs(vector<vector<char>>& board, queue<Pt>& pts, int m, int n)
	{
		while (!pts.empty())
		{
			Pt pt = pts.front();
			pts.pop();

			int row = pt.row;
			int col = pt.col;

			if (board[row][col] == 'O')
			{
				board[row][col] = '#';

				int _row = pt.row - 1;
				int row_ = pt.row + 1;
				int _col = pt.col - 1;
				int col_ = pt.col + 1;

				if (_row >= 0 && board[_row][col] == 'O') pts.push(Pt(_row, col));
				if (row_ < m  && board[row_][col] == 'O') pts.push(Pt(row_, col));
				if (_col >= 0 && board[row][_col] == 'O') pts.push(Pt(row, _col));
				if (col_ < n  && board[row][col_] == 'O') pts.push(Pt(row, col_));
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