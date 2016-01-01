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

		for (int i = 0; i < len; i++)
		{
			if (idxs.empty())
			{
				ret = max(ret, height[i] * (i + 1));
			}
			else
			{
				while (!idxs.empty() && height[idxs.top()] > height[i])
				{
					int h = height[idxs.top()];
					idxs.pop();
					int w = idxs.empty() ? i : i - idxs.top() - 1;
					ret = max(ret, h * w);
				}
			}
			idxs.push(i);
		}
		return ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}