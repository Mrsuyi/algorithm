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
	int removeDuplicates(vector<int>& nums)
	{
		int len = nums.size();
		if (len < 2) return len;
		int ret = 2;

		for (int i = 2; i < len; i++)
		{
			if (nums[i] != nums[ret - 2])
			{
				nums[ret++] = nums[i];
			}
		}
		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}