#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int ret = INT_MIN;
		int l = 0;
		int r = height.size() - 1;

		while (l != r)
		{
			int x = r - l;
			int y = min(height[r], height[l]);
			ret = max(ret, x * y);

			if (height[r] > height[l])
			{
				while (++l < r && height[l] < y) {}
			}
			else
			{
				while (--r > l && height[r] < y) {}
			}
		}
		return ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}