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
	vector<vector<int>> generateMatrix(int n)
	{
		int len = n;

		if (n == 0) return {};

		vector<vector<int>> ret = vector<vector<int>>(n, vector<int>(n, 0));

		// direction
		int dir = RIGHT;
		// border
		int left = 0, right = len - 1, up = 0, down = len - 1;
		// index
		int i_row = 0, i_col = 0;
		// cnt
		int cnt = 1;

		bool spire = true;
		while (spire)
		{
			switch (dir)
			{
			case RIGHT:
				for (; i_col < right; i_col++) ret[i_row][i_col] = cnt++;
				up++;
				if (down == i_row) spire = false;
				dir = DOWN;
				break;

			case DOWN:
				for (; i_row < down; i_row++) ret[i_row][i_col] = cnt++;
				right--;
				if (left == i_col) spire = false;
				dir = LEFT;
				break;

			case LEFT:
				for (; i_col > left; i_col--) ret[i_row][i_col] = cnt++;
				down--;
				if (up == i_row) spire = false;
				dir = UP;
				break;

			case UP:
				for (; i_row > up; i_row--) ret[i_row][i_col] = cnt++;
				left++;
				if (right == i_col) spire = false;
				dir = RIGHT;
				break;
			}
		}
		ret[i_row][i_col] = cnt++;
		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}