#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
	int dp[10000] = { 1, 2 };
	int dp_len = 2;

public:
	int climbStairs(int n)
	{
		int i = n - 1;

		while (dp_len <= i)
		{
			dp[dp_len++] = dp[dp_len - 1] + dp[dp_len - 2];
		}

		return dp[i];
	}
};

int main()
{
	Solution solution;

	int input;

	while (cin >> input)
	{
		cout << solution.climbStairs(input) << endl;
	}

	while (getchar());

	return 0;
}