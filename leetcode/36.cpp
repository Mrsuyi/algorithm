#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		bool row[9][9] = { 0 };
		bool col[9][9] = { 0 };
		bool block[9][9] = { 0 };

		for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
			{
				continue;
			}
			else
			{
				int num = board[i][j] - '1';
				int b = (i / 3) * 3 + j / 3;

				if (row[i][num] || col[j][num] || block[b][num])
				{
					return false;
				}
				else
				{
					row[i][num] = true;
					col[j][num] = true;
					block[b][num] = true;
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}