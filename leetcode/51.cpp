#include <iostream>
#include <vector>
#include <string>

using namespace std;

// recursion
class Solution
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> ret;

		vector<string> board(n, string(n, '.'));
		vector<bool> cols(n, false);
		vector<bool> dia1(2 * n - 1, false);
		vector<bool> dia2(2 * n - 1, false);

		dfs(ret, board, cols, dia1, dia2, 0, n);

		return ret;
	}

	void dfs(vector<vector<string>>& ret,
		     vector<string>& board,
		     vector<bool>& cols,
			 vector<bool>& dig1,
			 vector<bool>& dig2,
			 int row, int n)
	{
		if (row == n)
		{
			ret.push_back(board);
			return;
		}

		for (int col = 0; col < n; col++)
		{
			int dg1 = row - col + n - 1;
			int dg2 = row + col;

			if (!cols[col] && !dig1[dg1] && !dig2[dg2])
			{
				cols[col] = true;
				dig1[dg1] = true;
				dig2[dg2] = true;

				board[row][col] = 'Q';
				dfs(ret, board, cols, dig1, dig2, row + 1, n);
				board[row][col] = '.';

				cols[col] = false;
				dig1[dg1] = false;
				dig2[dg2] = false;
			}
		}
	}
};


// no recursion
class Solution
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> ret;

		vector<string> board(n, string(n, '.'));
		vector<int> idx(n, -1);
		vector<bool> cols(n, false);
		vector<bool> dig1(2 * n - 1, false);
		vector<bool> dig2(2 * n - 1, false);

		int row = 0;
		while (row >= 0)
		{
			if (row == n)
			{
				ret.push_back(board);
				row--;
				continue;
			}

			if (idx[row] == n)
			{
				idx[row] = -1;
				row--;
				continue;
			}

			if (idx[row] != -1)
			{
				int col = idx[row];
				int dg1 = row - col + n - 1;
				int dg2 = row + col;

				board[row][col] = '.';

				cols[col] = false;
				dig1[dg1] = false;
				dig2[dg2] = false;
			}
			idx[row]++;

			while (idx[row] < n)
			{
				int col = idx[row];
				int dg1 = row - col + n - 1;
				int dg2 = row + col;

				if (!cols[col] && !dig1[dg1] && !dig2[dg2])
				{
					cols[col] = true;
					dig1[dg1] = true;
					dig2[dg2] = true;

					board[row][col] = 'Q';
					row++;
					break;
				}

				idx[row]++;
			}
		}

		return ret;
	}
};


int main()
{
	Solution solution;

	solution.solveNQueens(4);

	while (getchar());

	return 0;
}