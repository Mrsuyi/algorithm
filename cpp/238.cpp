#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		int size = nums.size();
		vector<int> ret(size, 1);

		int l = nums[0];
		int r = nums[size - 1];
		for (int i = 1, j = size -2; i < size; i++, j--)
		{
			ret[i] *= l;
			ret[j] *= r;
			l *= nums[i];
			r *= nums[j];
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