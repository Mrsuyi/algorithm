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
	void gameOfLife(vector<vector<int>>& board)
	{
		int m = board.size();
		if (m == 0) return;
		int n = board[0].size();

		for (int i(0); i < m; i++)
		for (int j(0); j < n; j++)
		{
			int cnt = -board[i][j];
			for (int tp(max(0, i - 1)), bm(min(m - 1, i + 1)), p(tp); p <= bm; p++)
			for (int lf(max(0, j - 1)), rt(min(n - 1, j + 1)), q(lf); q <= rt; q++)
			{
				cnt += board[p][q] & 1;
			}
			board[i][j] |= (board[i][j] ? (cnt >= 2 && cnt <= 3) : (cnt == 3)) << 1;
		}

		for (int i(0); i < m; i++)
		for (int j(0); j < n; j++)
		{
			board[i][j] >>= 1;
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}