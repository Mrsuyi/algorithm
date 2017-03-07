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
	int countDigitOne(int n)
	{
		int ret = 0, base = 1, r = 1;
		while (n)
		{
			ret += (n + 8) / 10 * base + (n % 10 == 1) * r;
			r += (n % 10) * base;
			base *= 10;
			n /= 10;
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