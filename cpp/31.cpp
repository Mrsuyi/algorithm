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
			if (nums[i] < nums[i + 1])
			{
				int idx = i + 1;
				for (int j = i + 2; j < nums.size(); j++)
				{
					if (nums[j] > nums[i] && nums[j] < nums[idx])
					{
						idx = j;
					}
				}
				int tmp = nums[i];
				nums[i] = nums[idx];
				nums[idx] = tmp;
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