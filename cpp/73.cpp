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
	void setZeroes(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();

		// check row-0
		bool row0_zero = false;
		for (int j = 0; j < n; j++)
		{
			if (matrix[0][j] == 0)
			{
				row0_zero = true;
				break;
			}
		}

		// set rows and mark cols
		for (int i = 1; i < m; i++)
		{
			bool zero = false;
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					zero = true;
				}
			}
			if (zero)
			{
				for (int j = 0; j < n; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}

		// set cols
		for (int j = 0; j < n; j++)
		{
			if (matrix[0][j] == 0)
			{
				for (int i = 1; i < m; i++)
				{
					matrix[i][j] = 0;
				}
			}
		}

		// set row-0
		if (row0_zero)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[0][j] = 0;
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