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

		// get row
		int l = 0, r = m, mid = (l + r) / 2;
		while (l != mid)
		{
			if (matrix[mid][0] == target) return true;

			if (matrix[mid][0] > target) r = mid; else l = mid;

			mid = (l + r) / 2;
		}
		if (matrix[l][0] == target) return true;

		// get col
		int row = l;
		return binary_search(matrix[l].begin(), matrix[l].end(), target);
	}
};

int main()
{
	Solution solution;

	vector<vector<int>> matrix =
	{
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};

	cout << solution.searchMatrix(matrix, 8);

	while (getchar());

	return 0;
}