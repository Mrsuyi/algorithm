#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int ret = 0;
		for (int a : nums)
		{
			ret ^= a;
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