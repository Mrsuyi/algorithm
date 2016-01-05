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
		int l = 1, r = x, mid;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			int quo = x / mid;

			if (quo == mid)
			{
				return mid;
			}
			else if (quo < mid)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		return l - 1;
	}
};

int main()
{
	Solution solution;

	solution.mySqrt(2147483647);

	while (getchar());

	return 0;
}