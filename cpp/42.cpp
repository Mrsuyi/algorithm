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
	int trap(vector<int>& height)
	{
		int len = height.size();

		vector<int> l(len, 0);
		vector<int> r(len, 0);

		for (int i = 1, j = len - 2; i < len; i++, j--)
		{
			l[i] = max(l[i - 1], height[i - 1]);
			r[j] = max(r[j + 1], height[j + 1]);
		}

		int ret = 0;
		for (int i = 0; i < len; i++)
		{
			int h = min(l[i], r[i]);
			if (h > height[i])
			{
				ret += h - height[i];
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