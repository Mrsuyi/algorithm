#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
#define LEFT  0
#define RIGHT 1
#define UP    2
#define DOWN  3

public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		int row = matrix.size(), col;
		if (row == 0) return {};
		col = matrix[0].size();

		vector<int> ret;

		// direction
		int dir = RIGHT;
		// border
		int left = 0, right = col - 1, up = 0, down = row - 1;
		int i_row = 0, i_col = 0;

		bool spire = true;
		while (spire)
		{
			switch (dir)
			{
				case RIGHT:
					for (; i_col < right; i_col++) ret.push_back(matrix[i_row][i_col]);
					up++;
					if (down == i_row) spire = false;
					dir = DOWN;
					break;

				case DOWN:
					for (; i_row < down; i_row++) ret.push_back(matrix[i_row][i_col]);
					right--;
					if (left == i_col) spire = false;
					dir = LEFT;
					break;

				case LEFT:
					for (; i_col > left; i_col--) ret.push_back(matrix[i_row][i_col]);
					down--;
					if (up == i_row) spire = false;
					dir = UP;
					break;

				case UP:
					for (; i_row > up; i_row--) ret.push_back(matrix[i_row][i_col]);
					left++;
					if (right == i_col) spire = false;
					dir = RIGHT;
					break;
			}
		}
		ret.push_back(matrix[i_row][i_col]);
		return ret;
	}
};

int main()
{
	Solution solution;

	vector<vector<int>> matrix = { {1,2,3}, {4, 5, 6}, {7, 8, 9} };

	solution.spiralOrder(matrix);

	while (getchar());

	return 0;
}