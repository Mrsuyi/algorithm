#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		int ret = INT_MAX;
		int sum = 0;
		int i = 0;
		int cnt = 0;
		
		for (int n : nums)
		{
			sum += n;
			cnt++;

			while (sum >= s)
			{
				if (sum >= s && cnt < ret) ret = cnt;

				sum -= nums[i++];
				cnt--;
			}
		}

		return ret == INT_MAX ? 0 : ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}