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
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		int n = matrix[0].size();

		int l = 0, r = m - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;

			if (matrix[mid][0] == target)
			{
				return true;
			}
			else if (matrix[mid][0] > target)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		if (l == 0) return false;

		return binary_search(matrix[l - 1].begin(), matrix[l - 1].end(), target);
	}
};

int main()
{
	while (getchar());

	return 0;
}