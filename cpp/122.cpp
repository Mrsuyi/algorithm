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
	int maxProfit(vector<int>& prices)
	{
		int len = prices.size();
		if (len == 0) return 0;

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
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}