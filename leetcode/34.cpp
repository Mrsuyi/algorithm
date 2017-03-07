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
	vector<int> searchRange(vector<int>& nums, int target)
	{
		auto l = upper_bound(nums.begin(), nums.end(), target - 1);
		auto r = upper_bound(nums.begin(), nums.end(), target);

		if (l == nums.end() || *l != target)
		{
			return { -1, -1 };
		}
		else
		{
			return { l - nums.begin(), r - nums.begin() - 1 };
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}