#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
private:
	inline int max(const int a, const int b) { return a > b ? a : b; };
	inline int min(const int a, const int b) { return a < b ? a : b; };
public:
	int maxProfit(vector<int>& prices)
	{
		int len = prices.size();
		if (len == 0) return 0;

		int ret = 0;
		int buy = prices[0];
		for (int i = 1; i < len; i++)
		{
			ret = max(prices[i] - buy, ret);
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