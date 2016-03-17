#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		int len = nums.size();
		if (len == 0 || len < k) return {};

		vector<int> ret(len - k + 1);
		deque<int> q;

		for (int i = 0; i < len; i++)
		{
			if (!q.empty() && q.front() <= i - k)
			{ 
				q.pop_front();
			}
			while (!q.empty() && nums[i] > nums[q.back()])
			{
				q.pop_back();
			}
			q.push_back(i);
			
			if (i >= k - 1)
			{
				ret[i - k + 1] = nums[q.front()];
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