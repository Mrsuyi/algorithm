#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
private:
	inline int max(int a, int b) { return a > b ? a : b; }

public:
	int rob(vector<int>& nums)
	{
		int size = nums.size();

		if (size < 3)
		{
			if (size == 0) return 0;
			if (size == 1) return nums[0];
			if (size == 2) return max(nums[0], nums[1]);
		}

		int y_y = nums[0] + nums[2];
		int y_n = nums[0];
		int n_y = nums[2];
		int n_n = nums[1];

		for (int i = 3; i < size; i++)
		{
			int tmp = y_y;
			y_y = y_n + nums[i];
			y_n = max(y_n, tmp);

			tmp = n_y;
			n_y = n_n + nums[i];
			n_n = max(n_n, tmp);
		}

		return max(y_n, max(n_y, n_n));
	}
};

int main()
{
	while (getchar());

	return 0;
}