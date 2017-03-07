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
		int ret = 0;
		for (int i = 0, buy = INT_MAX; i < prices.size(); i++)
		{
			ret = max(ret, prices[i] - buy);
			buy = min(buy, prices[i]);
		}
		return ret;
	}
};

int main()
{
	Solution solution;

	vector<int> input = { 1, 2 };

	solution.maxProfit(input);

	while (getchar());

	return 0;
}