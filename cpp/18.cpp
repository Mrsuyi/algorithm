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
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		int len = nums.size();
		vector<vector<int>> ret;

		sort(nums.begin(), nums.end());

		// 1
		for (int i = 0; i < len - 3; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1]) continue;

			// 2
			for (int j = i + 1; j < len - 2; j++)
			{
				if (j != i + 1 && nums[j] == nums[j - 1]) continue;

				// 3 & 4
				int min = j + 1, max = len - 1;

				int l = min, r = max;

				while (l < r)
				{
					int sum = nums[l] + nums[r];
					int rest = target - nums[i] - nums[j];

					if (sum < rest)
					{
						l++;
					}
					else if (sum > rest)
					{
						r--;
					}
					else
					{
						ret.push_back({ nums[i], nums[j], nums[l], nums[r] });
						
						while (++l < max && nums[l] == nums[l - 1]) {};
						while (--r > min && nums[r] == nums[r + 1]) {};
					}
				}
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