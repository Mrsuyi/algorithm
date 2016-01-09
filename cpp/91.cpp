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
	int numDecodings(string s)
	{
		int len = s.size();
		if (len == 0) return 0;
		int dp1 = s[0] != '0', dp2 = 1;

		for (int i = 1; i < s.size(); i++)
		{
			int tmp = dp1;

			if (s[i] == '0')
			{
				dp1 = 0;
			}
			if ((s[i - 1] == '1')
			 || (s[i - 1] == '2' && s[i] <= '6'))
			{
				dp1 += dp2;
			}
			dp2 = tmp;
		}
		return dp1;
	}
};

int main()
{
	Solution solution;

	cout << solution.numDecodings("12321") << endl;

	while (getchar());

	return 0;
}