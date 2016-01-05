#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int climbStairs(int n)
	{
		int dp[10000] = { 1, 2 };
		for (int i = 2; i < n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n - 1];
	}
};

int main()
{
	while (getchar());

	return 0;
}