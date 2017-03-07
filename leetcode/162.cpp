#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int findPeakElement(vector<int>& nums)
	{
		int l = 0, r = nums.size() - 1;

		while (l < r)
		{
			int mid = l + (r - l) / 2;

			if (nums[mid] < nums[l])
			{
				r = mid - 1;
			}
			else if (nums[mid] < nums[r])
			{
				l = mid + 1;
			}
			else
			{
				r--;
			}
		}

		return l;
	}
};

int main()
{

	while (getchar());

	return 0;
}