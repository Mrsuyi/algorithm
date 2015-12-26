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
	int threeSumClosest(vector<int>& nums, int target)
	{
		int ret;
		int diff = INT_MAX;
		int len = nums.size();

		sort(nums.begin(), nums.end());

		for (int i = 0; i < len - 2; i++)
		{
			int j = i + 1, k = len - 1;

			while (j < k)
			{
				int s = nums[i] + nums[j] + nums[k];
				int d = target - s;
				if (d == 0) return s;

				d > 0 ? j++ : k--;

				d = abs(d);
				if (d < diff)
				{
					diff = d;
					ret = s;
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