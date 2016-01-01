#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Mrsuyi
class Solution
{
public:
	int numDistinct(string s, string t)
	{
		int l1 = s.size();
		int l2 = t.size();
		if (l1 == 0 || l2 == 0) return 0;

		vector<int> dp(l1);

		for (int i = 0; i < l2; i++)
		{
			vector<int> tmp(l1, 0);
			for (int j = 0, cnt = i == 0; j < l1; j++)
			{
				if (cnt && s[j] == t[i])
				{
					tmp[j] = cnt;
				}
				cnt += dp[j];
			}
			dp = tmp;
		}
		
		int ret = 0;
		for (int n : dp)
		{
			ret += n;
		}
		return ret;
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