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
	int numDistinct(string s, string t)
	{
		vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
		fill(dp[0].begin(), dp[0].end(), 1);

		for (int i = 1; i <= t.size(); i++)
		for (int j = 1; j <= s.size(); j++)
		{
			dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
		}
		return dp[t.size()][s.size()];
	}
};

// https://leetcode.com/discuss/73299/my-solution-with-c-in-o-t-s-time-and-o-t-space
class Solution
{
public:
	int numDistinct(string s, string t) {
		int res=0;
		int i,j,k;
		vector<int> counter(t.size(),0);
		for(i=0;i<s.size();i++) {
			for(j=t.size()-1;j>=0;j--) {
				if(t[j]==s[i]) {
					if(j) counter[j]+=counter[j-1];
					else counter[j]++;
				}
			}
		}
		return counter.back();
	}
};

//https://leetcode.com/discuss/62028/4ms-c-solution-with-explanation-space-time-in-the-worst-case
// same as above


int main()
{
	Solution solution;

	while (getchar());

	return 0;
}