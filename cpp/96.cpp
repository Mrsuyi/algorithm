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
	int numTrees(int n)
	{
		vector<int> dp = vector<int>(n + 1, 0);

		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i <= n; i++)
		{
			int sum = 0;
			for (int j = 0; j < i; j++)
			{
				sum += dp[j] * dp[i - j - 1];
			}
			dp[i] = sum;
		}

		return dp[n];
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}