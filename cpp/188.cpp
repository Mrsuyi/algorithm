#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	int maxProfit(int k, vector<int>& prices)
	{
		int len = prices.size();
		if (len < 2 || k < 1) return 0;

		if (k > len / 2)
		{
			int ret = 0;
			for (int i = 1; i < len; i++)
			{
				if (prices[i] > prices[i - 1])
				{
					ret += prices[i] - prices[i - 1];
				}
			}
			return ret;
		}
		else
		{
			vector<int> buy(k + 1, INT_MIN);
			vector<int> sel(k + 1, INT_MIN);
			sel[0] = 0;

			for (int n : prices)
			{
				for (int i = 1; sel[i - 1] != INT_MIN && i <= k; i++)
				{
					buy[i] = max(buy[i], sel[i - 1] - n);
					sel[i] = max(sel[i], buy[i] + n);
				}
			}

			return *max_element(sel.begin(), sel.end());
		}
	}
};

int main()
{
	while (getchar());

	return 0;
}