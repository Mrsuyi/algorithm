#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	int dp(vector<int> nums)
	{
		int yes = nums[0];
		int no = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			int tmp = yes;
			yes = nums[i] + no;
			no = max(no, tmp);
		}

		return max(yes, no);
	}

	int rob(vector<int>& nums)
	{
		int len = nums.size();

		if (len == 0) return 0;
		if (len == 1) return nums[0];

		return max(dp(vector<int>(nums.begin(), nums.end() - 1)), dp(vector<int>(nums.begin() + 1, nums.end())));
	}
};

int main()
{
	while (getchar());

	return 0;
}