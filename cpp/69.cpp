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
	int mySqrt(int x)
	{
		if (x == 0 || x == 1) return x;

		int l = 0, r = x, mid = (l + r) / 2;

		while (l < r)
		{
			int quo = x / mid;

			     if (quo == mid) break;
			else if (quo < mid)  r = mid - 1;
			else                 l = mid + 1;

			mid = (l + r) / 2;
		}

		while (mid * mid > x) mid--;
		return mid;
	}
};

int main()
{
	Solution solution;

	solution.mySqrt(2147483647);

	while (getchar());

	return 0;
}