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
	vector<vector<char>> board;
	string word;
	int len, m, n;

	bool exist(vector<vector<char>>& board, string word)
	{
		this->m = board.size();
		this->n = board[0].size();
		this->word = word;
		this->len = word.size();
		this->board = board;

		for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (dfs(0, i, j)) return true;
		}
		return false;
	}

	bool dfs(int idx, int row, int col)
	{
		if (idx == len - 1) return board[row][col] == word[idx];
		if (board[row][col] != word[idx]) return false;

		char c = board[row][col];
		board[row][col] = '#';

		int _row = row - 1;
		int row_ = row + 1;
		int _col = col - 1;
		int col_ = col + 1;

		bool ret = (_col >= 0 && dfs(idx + 1, row, _col))
			    || (col_ < n  && dfs(idx + 1, row, col_))
			    || (_row >= 0 && dfs(idx + 1, _row, col))
			    || (row_ < m  && dfs(idx + 1, row_, col));

		board[row][col] = c;

		return ret;
	}
};

int main()
{
	Solution solution;

	vector<vector<char>> board = { { 'A','B','C','E' },{ 'S','F','C','S' },{ 'A','D','E','E' } };

	cout << solution.exist(board, "ABCCED") << endl;

	while (getchar());

	return 0;
}