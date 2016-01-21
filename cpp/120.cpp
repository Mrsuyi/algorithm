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
	int minimumTotal(vector<vector<int>>& triangle)
	{
		vector<int> dp(triangle.size() + 1, INT_MAX);
		vector<int> tmp(triangle.size() + 1, INT_MAX);

		dp[1] = 0;
		for (int i = 0; i < triangle.size(); i++)
		{
			for (int j = 1; j <= i + 1; j++)
			{
				tmp[j] = triangle[i][j - 1] + min(dp[j], dp[j - 1]);
			}
			swap(dp, tmp);
		}
		return *min_element(dp.begin(), dp.end());
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}