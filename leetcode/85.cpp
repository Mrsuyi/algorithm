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
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();

		int ret = INT_MIN;
		vector<int> lst(n, 0);

		for (int i = 0; i < m; i++)
		{
			vector<int> h(n, 0);

			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
				{
					h[j] = lst[j] + 1;
				}
			}
			ret = max(ret, largestRectangleArea(h));
			lst = h;
		}

		return ret;
	}

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
	Solution solution;

	while (getchar());

	return 0;
}