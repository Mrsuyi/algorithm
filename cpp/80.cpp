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

		if (len <= 1) return len;

		int ret = 1;
		int last = nums[0];
		int cnt = 1;
		for (int i = 1; i < len; i++)
		{
			if (nums[i] == last)
			{
				if (cnt == 1)
				{
					nums[ret] = nums[i];
					ret++;
				}
				cnt++;
			}
			else
			{
				last = nums[i];
				nums[ret] = nums[i];
				ret++;
				cnt = 1;
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