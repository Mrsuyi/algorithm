#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	inline string str(int a, int b)
	{
		if (a == b)
		{
			return to_string(a);
		}
		else
		{
			return to_string(a) + "->" + to_string(b);
		}
	}

	vector<string> summaryRanges(vector<int>& nums)
	{
		vector<string> ret;

		int i = 0;

		while (i < nums.size())
		{
			int bgn = i++;
			while (i < nums.size() && nums[i] == nums[i - 1] + 1) { i++; }
			ret.push_back(str(nums[bgn], nums[i - 1]));
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