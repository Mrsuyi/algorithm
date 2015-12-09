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
	vector<vector<char>> bd;
	string wd;
	vector<vector<bool>> visited;
	int m_max, n_max, last;

	bool exist(vector<vector<char>>& board, string word)
	{
		bd = board;
		wd = word;

		m_max = board.size();
		n_max = board[0].size();
		last = word.length() - 1;

		visited = vector<vector<bool>>(m_max, vector<bool>(n_max, false));

		for (int i = 0; i < m_max; i++)
		for (int j = 0; j < n_max; j++)
		{
			if (dfs(i, j, 0)) return true;
		}

		return false;
	}

	bool dfs(int m, int n, int idx)
	{
		if (idx == last)
		{
			return bd[m][n] == wd[idx];
		}
		else if (bd[m][n] == wd[idx])
		{
			visited[m][n] = true;

			int _n = n - 1;
			int n_ = n + 1;
			int _m = m - 1;
			int m_ = m + 1;

			idx++;

			bool search = (_n >= 0    && !visited[m][_n] && dfs(m, _n, idx))
		               || (n_ < n_max && !visited[m][n_] && dfs(m, n_, idx))
				       || (_m >= 0    && !visited[_m][n] && dfs(_m, n, idx))
					   || (m_ < m_max && !visited[m_][n] && dfs(m_, n, idx));

			visited[m][n] = false;

			return search;
		}
		else
		{
			return false;
		}
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