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
	vector<vector<int>> subsets(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());

		vector<vector<int>> ret;
		
		int len = nums.size();
		int cnt = 1 << len;
		for (int i = 0; i < cnt; i++)
		{
			vector<int> v;
			for (int j = 0; j < len; j++)
			{
				if (i & 1 << j)
				{
					v.push_back(nums[j]);
				}
			}
			ret.push_back(v);
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