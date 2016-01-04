#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int totalNQueens(int n)
	{
		int ret = 0;

		vector<bool> cols(n, false);
		vector<bool> dia1(2 * n - 1, false);
		vector<bool> dia2(2 * n - 1, false);

		dfs(ret, cols, dia1, dia2, 0, n);

		return ret;
	}

	void dfs(int& ret,
		     vector<bool>& cols,
			 vector<bool>& dig1,
			 vector<bool>& dig2,
			 int row, int n)
	{
		if (row == n)
		{
			ret++;
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

				dfs(ret, cols, dig1, dig2, row + 1, n);

				cols[col] = false;
				dig1[dg1] = false;
				dig2[dg2] = false;
			}
		}
	}
};


int main()
{
	Solution solution;

	solution.solveNQueens(4);

	while (getchar());

	return 0;
}