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
	void nextPermutation(vector<int>& nums)
	{
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			int min = INT_MAX;
			int i_min;
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] > nums[i] && nums[j] < min)
				{
					i_min = j;
					min = nums[j];
				}
			}
			if (min != INT_MAX)
			{
				int tmp = nums[i];
				nums[i] = nums[i_min];
				nums[i_min] = tmp;
				sort(nums.begin() + i + 1, nums.end());
				return;
			}
		}
		reverse(nums.begin(), nums.end());
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}