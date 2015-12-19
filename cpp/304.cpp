#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class NumMatrix
{
private:
	vector<vector<int>> sum;

public:
	NumMatrix(vector<vector<int>> &matrix)
	{
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();

		sum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

		for (int i(1); i <= m; i++)
		for (int j(1); j <= n; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
	}
};

int main()
{
	while (getchar());

	return 0;
}