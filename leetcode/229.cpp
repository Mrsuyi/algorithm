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
	vector<int> majorityElement(vector<int>& nums)
	{
		int len = nums.size();
		vector<int> ret;
		int n_1, n_2, c_1, c_2;
		n_1 = n_2 = c_1 = c_2 = 0;

		for (auto n: nums)
		{
			if (n_1 == n)
			{
				c_1++;
			}
			else if (n_2 == n)
			{
				c_2++;
			}
			else if (c_1 == 0)
			{
				n_1 = n;
				c_1 = 1;
			}
			else if (c_2 == 0)
			{
				n_2 = n;
				c_2 = 1;
			}
			else
			{
				c_1--;
				c_2--;
			}
		}

		c_1 = c_2 = 0;
		for (auto n : nums)
		{
			if (n == n_1)
			{
				c_1++;
			}
			else if (n == n_2)
			{
				c_2++;
			}
		}

		if (c_1 > len / 3) ret.push_back(n_1);
		if (c_2 > len / 3 && n_2 != n_1) ret.push_back(n_2);

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}