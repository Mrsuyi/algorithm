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
		int len = nums.size();
		if (len == 0) return 0;

		int ret = INT_MIN;
		int mul = 1;
		int mul_m = 0;

		for (int n : nums)
		{
			if (n == 0)
			{
				if (0 > ret) ret = 0;
				mul = 1;
				mul_m = 0;
			}
			else
			{
				if (mul < 0 && mul_m == 0)
				{
					mul_m = 1;
				}
				if (mul_m != 0)
				{
					mul_m *= n;
					if (mul_m > ret) ret = mul_m;
				}

				mul *= n;
				if (mul > ret) ret = mul;
			}
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