#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	int rangeBitwiseAnd(int m, int n)
	{
		int ret = 0;
		unsigned mask = 1 << 31;
		while (mask)
		{
			if (n & mask)
			{
				if (m & mask)
				{
					ret |= mask;
				}
				else
				{
					return ret;
				}
			}
			mask >>= 1;
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