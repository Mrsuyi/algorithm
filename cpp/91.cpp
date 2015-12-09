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

		vector<int> cache = vector<int>(len + 1, -1);

		cache[len] = 1;
		cache[len - 1] = s[len - 1] != '0';

		return dp(cache, s, 0);
	}

	int dp(vector<int>& cache, string& s, int idx)
	{
		if (cache[idx] != -1) return cache[idx];

		if (s[idx] == '0')
		{
			return cache[idx] = 0;
		}
		else if (s[idx] > '2' || (s[idx] == '2' && s[idx + 1] > '6'))
		{
			return cache[idx] = dp(cache, s, idx + 1);
		}
		else
		{
			return cache[idx] = dp(cache, s, idx + 1) + dp(cache, s, idx + 2);
		}
	}
};

int main()
{
	Solution solution;

	solution.numDecodings("12321");

	while (getchar());

	return 0;
}