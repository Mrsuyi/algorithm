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

class Solution
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();

		int i = 0, j = n - 1;

		while (i < m && j >= 0)
		{
			int cmp = matrix[i][j];
			if (cmp == target)
			{
				return true;
			}
			else if (cmp > target)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		return false;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}