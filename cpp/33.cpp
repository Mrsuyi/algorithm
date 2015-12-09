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
	int search(vector<int>& nums, int target)
	{
		int len = nums.size();

		int l = 0, r = len - 1;

		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);

			if (nums[mid] == target)
			{
				return mid;
			}
			
			if (nums[mid] >= nums[l])
			{
				target >= nums[l] && target < nums[mid] ? r = mid - 1 : l = mid + 1;
			}
			else
			{
				target > nums[mid] && target <= nums[r] ? l = mid + 1 : r = mid - 1;
			}
		}
		return -1;
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