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
public:
	int maxProduct(vector<int>& nums)
	{
		if (nums.size() == 1) return nums[0];
		int ret = INT_MIN;
		int mx = 0, mi = 0;

		for (int n : nums)
		{
			int tx = mx * n;
			int ti = mi * n;
			mx = max(n, max(tx, ti));
			mi = min(n, min(tx, ti));
			ret = max(ret, mx);
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}