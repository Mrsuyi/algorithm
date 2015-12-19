#include <iostream>
#include <vector>
#include <stack>
#include <string>
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
	int missingNumber(vector<int>& nums)
	{
		int len = nums.size();
		long long sum(0);

		for (auto n : nums)
		{
			sum += n;
		}

		return ((len * (len + 1)) >> 1) - sum;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}