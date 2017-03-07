#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	void solveSudoku(vector<vector<char>>& board)
	{
		vector<vector<bool>> rows(9, vector<bool>(9, false));
		vector<vector<bool>> cols(9, vector<bool>(9, false));
		vector<vector<bool>> blks(9, vector<bool>(9, false));

		for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				rows[i][board[i][j] - '1'] = true;
				cols[j][board[i][j] - '1'] = true;
				blks[(i / 3) * 3 + j / 3][board[i][j] - '1'] = true;
			}
		}

		dfs(board, rows, cols, blks, 0);
	}

	bool dfs(vector<vector<char>>& board,
		     vector<vector<bool>>& rows,
		     vector<vector<bool>>& cols,
		     vector<vector<bool>>& blks,
			 int idx)
	{
		if (idx == 81) return true;

		int row = idx / 9;
		int col = idx % 9;
		int blk = (row / 3) * 3 + col / 3;

		if (board[row][col] == '.')
		{
			for (int k = 0; k < 9; k++)
			{
				if (!rows[row][k] && !cols[col][k] && !blks[blk][k])
				{
					rows[row][k] = true;
					cols[col][k] = true;
					blks[blk][k] = true;

					board[row][col] = '1' + k;
					if (dfs(board, rows, cols, blks, idx + 1)) return true;
					board[row][col] = '.';

					rows[row][k] = false;
					cols[col][k] = false;
					blks[blk][k] = false;
				}
			}
			return false;
		}
		else
		{
			return dfs(board, rows, cols, blks, idx + 1);
		}
	}
};

int main()
{

	while (getchar());

	return 0;
}