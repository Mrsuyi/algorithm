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
	int jump(vector<int>& nums)
	{
		int len = nums.size();
		if (len < 2) return 0;
		int bgn = 0;
		int end = 0;
		int ret = 0;

		while (true)
		{
			int far = end;
			for (int i = bgn; i <= end; i++)
			{
				far = max(far, i + nums[i]);
				if (far >= len - 1) return ret + 1;
			}
			bgn = end + 1;
			end = far;
			ret++;
		}
	}
};

class Solution
{
public:
	int jump(vector<int>& nums)
	{
		int len = nums.size();
		if (len < 2) return 0;

		vector<int> dp(len, INT_MAX);
		dp[0] = 0;
		
		for (int i = 0, j = 0; i < len; i++)
		{
			int far = i + nums[i];

			if (far >= len - 1) return dp[i] + 1;

			for (int k = j + 1; k <= far; k++)
			{
				dp[k] = dp[i] + 1;
			}

			if (far > j) j = far;
		}

		return dp[len - 1];
	}
};

int main()
{
	while (getchar());

	return 0;
}