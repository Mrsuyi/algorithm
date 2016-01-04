#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int len = prices.size();
		if (len < 2) return 0;
		if (len == 2) return max(0, prices[1] - prices[0]);

		vector<int> buy1(len, 0);
		vector<int> sel1(len, 0);
		vector<int> buy2(len, 0);
		vector<int> sel2(len, 0);

		buy1[0] = -prices[0];
		buy1[1] = max(buy1[0], -prices[1]);
		buy1[2] = max(buy1[1], -prices[2]);
		sel1[1] = buy1[0] + prices[1];
		sel1[2] = max(sel1[1], buy1[1] + prices[2]);
		buy2[2] = sel1[1] - prices[2];

		for (int i = 3; i < len; i++)
		{
			buy1[i] = max(buy1[i - 1], -prices[i]);
			sel1[i] = max(sel1[i - 1], buy1[i - 1] + prices[i]);
			buy2[i] = max(buy2[i - 1], sel1[i - 1] - prices[i]);
			sel2[i] = max(sel2[i - 1], buy2[i - 1] + prices[i]);
		}

		return max(sel1[len - 1], sel2[len - 1]);
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}