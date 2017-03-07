#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution
{
public:
	int findDuplicate(vector<int>& nums)
	{
		int l = 1, r = nums.size() - 1;

		while (l < r)
		{
			int mid = l + (r - l) / 2;

			int cnt = 0;
			for (int n : nums)
			{
				if (n >= l && n <= mid)
				{
					cnt++;
				}
			}

			if (cnt > mid - l + 1)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}

		return l;
	}
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, finder = 0;

        while (1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break;
        }


        while (1)
        {
            finder = nums[finder];
            slow = nums[slow];

            if (finder == slow)
                return finder;
        }
    }
};


int main()
{
	Solution so;
	vector<int> input = { 8,1,1,1,2,7,4,3,1,1 };
	so.findDuplicate(input);

	while (getchar());

	return 0;
}