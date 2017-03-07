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
	vector<int> singleNumber(vector<int>& nums)
	{
		int x = 0;
		for (auto n : nums)
		{
			x ^= n;
		}

		x &= -x;
		int a(0), b(0);

		for (auto n : nums)
		{
			if (n & x)
			{
				a ^= n;
			}
			else
			{
				b ^= n;
			}
		}

		return { a, b };
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}