#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

#include <ctime>

using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		// find out the max-square
		int i_l = 0;
		int i_r = height.size() - 1;
		int max = INT_MIN;

		while (i_l != i_r)
		{
			int len_x = i_r - i_l;
			int len_y;

			if (height[i_r] > height[i_l])
			{
				len_y = height[i_l];
				while (++i_l < i_r && height[i_l] < len_y);
			}
			else
			{
				len_y = height[i_r];
				while (--i_r > i_l && height[i_r] < len_y);
			}

			int s = len_x * len_y;
			if (s > max) max = s;
		}

		return max;
	}
};

int main()
{
	Solution solution;


	while (getchar());

	return 0;
}