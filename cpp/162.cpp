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
	int findPeakElement(vector<int>& nums)
	{
		return search(nums, 0, nums.size() - 1);
	}

	int search(vector<int>& nums, int l, int r)
	{
		if (l >= r) return l;

		int mid = l + ((r - l) >> 1);

		if (nums[mid] < nums[l])
		{
			return search(nums, l, mid - 1);
		}
		else if (nums[mid] < nums[r])
		{
			return search(nums, mid + 1, r);
		}
		else
		{
			if (nums[mid] < nums[mid - 1])
			{
				return search(nums, l, mid - 1);
			}
			else if (nums[mid] < nums[mid + 1])
			{
				return search(nums, mid + 1, r);
			}
			else
			{
				return mid;
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