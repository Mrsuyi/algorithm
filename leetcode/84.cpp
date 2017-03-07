#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
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
	int largestRectangleArea(vector<int>& height)
	{
		height.push_back(0);
		int len = height.size();
		int ret = 0;
		stack<int> idxs;
		idxs.push(0);

		for (int i = 1; i < len; i++)
		{
			while (!idxs.empty() && height[idxs.top()] > height[i])
			{
				int h = height[idxs.top()];
				idxs.pop();
				int w = idxs.empty() ? i : i - idxs.top() - 1;
				ret = max(ret, h * w);
			}
			idxs.push(i);
		}
		return ret;
	}
};

class Solution
{
public:
	int largestRectangleArea(vector<int>& height)
	{
		height.push_back(0);
		int len = height.size();
		int ret = height[0];

		for (int i = 1; i < len; i++)
		{
			if (height[i - 1] > height[i])
			{
				int j = i - 1;
				while (j >= 0 && height[j] > height[i])
				{
					ret = max(ret, height[j] * (i - j));
					height[j] = height[i];
					j--;
				}
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