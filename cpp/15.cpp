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
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		if (nums.size() < 3) return {};

		sort(nums.begin(), nums.end());

		if (nums.front() == nums.back())
		{
			if (nums[0] == 0) return{ { 0, 0, 0 } }; else return{};
		}

		vector<vector<int>> ret;

		for (auto i = nums.begin(); i < nums.end() - 2;)
		{
			for (auto j = nums.end() - 1; j > i + 1;)
			{
				int rest = 0 - *i - *j;

				if (binary_search(i + 1, j, rest))
				{
					ret.push_back({ *i, rest, *j });
				}

				while (*--j == *(j + 1));
			}
			
			while (*++i == *(i - 1));
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	vector<int> input = { -1, 0, 1 };

	solution.threeSum(input);

	while (getchar());

	return 0;
}