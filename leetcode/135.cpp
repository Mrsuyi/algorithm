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
	int candy(vector<int>& ratings)
	{
		vector<int> nums = { INT_MAX };
		nums.insert(nums.end(), ratings.begin(), ratings.end());
		nums.push_back(INT_MAX);

		vector<int> candy(nums.size(), 0);

		for (int i = 1; i < nums.size() - 1; i++)
		{
			if (nums[i] > nums[i - 1])
			{
				candy[i] = candy[i - 1] + 1;
			}
			else if (nums[i] <= nums[i + 1])
			{
				candy[i] = 1;
			}
		}
		for (int i = nums.size() - 2; i >= 1; i--)
		{
			if (nums[i] > nums[i + 1])
			{
				candy[i] = max(candy[i], candy[i + 1] + 1);
			}
		}

		int ret = 0;
		for (int i = 1; i < candy.size() - 1; i++)
		{
			ret += candy[i];
		}
		return ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}