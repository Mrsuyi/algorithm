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
	int maxProfit(vector<int>& prices)
	{
		int len = prices.size();
		if (len == 0) return 0;

		int wait = 0;
		int hold = -prices[0];
		int cool = 0;

		for (int i = 1; i < len; i++)
		{
			int wait_ = max(wait, cool);
			int hold_ = max(hold, wait - prices[i]);
			int cool_ = hold + prices[i];
			wait = wait_;
			hold = hold_;
			cool = cool_;
		}

		return max(wait, max(hold, cool));
	}
};

int main()
{
	while (getchar());

	return 0;
}