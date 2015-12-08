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
	void sortColors(vector<int>& nums)
	{
		int len = nums.size();

		int i_0_end = -1, i_2_bgn = len, i = 0;

		while (i < i_2_bgn)
		{
			if (nums[i] == 0 && i != ++i_0_end)
			{
				int tmp = nums[i_0_end];
				nums[i_0_end] = nums[i];
				nums[i] = tmp;
			}
			else if (nums[i] == 2 && i != --i_2_bgn)
			{
				int tmp = nums[i_2_bgn];
				nums[i_2_bgn] = nums[i];
				nums[i] = tmp;
			}
			else
			{
				i++;
			}
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}