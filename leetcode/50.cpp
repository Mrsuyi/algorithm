#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
	double myPow(double x, int n)
	{
		unsigned e = abs(n);
		if (e == 0) return 1;

		double ret = 1;

		while (e)
		{
			double mul = x;
			long long i = 2;

			while (e >= i)
			{
				mul *= mul;
				i <<= 1;
			}

			e -= i >> 1;
			ret *= mul;
		}

		return n >> 31 ? 1 / ret : ret;
	}
};

//https://leetcode.com/discuss/17005/short-and-easy-to-understand-solution

int main()
{
	Solution solution;

	solution.myPow(1, INT_MIN);

	while (getchar());

	return 0;
}