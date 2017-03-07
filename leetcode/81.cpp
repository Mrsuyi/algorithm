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
	bool search(vector<int>& nums, int target)
	{
		int len = nums.size();

		return sch(nums, 0, len - 1, target);
	}

	bool sch(vector<int>& nums, int l, int r, int target)
	{
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);

			if (nums[mid] == target)
			{
				return true;
			}

			if (nums[mid] > nums[l] || nums[mid] > nums[r])
			{
				target >= nums[l] && target < nums[mid] ? r = mid - 1 : l = mid + 1;
			}
			else if (nums[mid] < nums[l] || nums[mid] < nums[r])
			{
				target > nums[mid] && target <= nums[r] ? l = mid + 1 : r = mid - 1;
			}
			else
			{
				return sch(nums, l + 1, mid - 1, target) || sch(nums, mid + 1, r - 1, target);
			}
		}
		return false;
	}
};

int main()
{
	Solution solution;

	vector<int> input = { 3,1 };
	
	cout << solution.search(input, 1);

	while (getchar());

	return 0;
}