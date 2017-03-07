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
	void rotate(vector<vector<int>>& matrix)
	{
		int len = matrix.size();
		int row = len / 2, col = len / 2 + len % 2;
		len--;

		for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			int tmp = matrix[i][j];
			int l_i = len - i, l_j = len - j;

			matrix[i][j] = matrix[l_j][i];
			matrix[l_j][i] = matrix[l_i][l_j];
			matrix[l_i][l_j] = matrix[j][l_i];
			matrix[j][l_i] = tmp;
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}