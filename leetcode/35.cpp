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
	int searchInsert(vector<int>& nums, int target)
	{
		return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}