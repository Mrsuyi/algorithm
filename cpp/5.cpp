#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

#include <ctime>

using namespace std;

inline int max(const int a, const int b) { return a > b ? a : b; };
inline int min(const int a, const int b) { return a < b ? a : b; };

// Manacher	
class Solution
{
public:
	string longestPalindrome(string s)
	{
		int len = s.length();
		if (len == 1) return s;

		// preprocess  aba -> ^#a#b#c$
		string str;
		str += '^';
		for (int i = 0; i < s.size(); i++)
		{
			str += '#';
			str += s[i];
		}
		str += "#$";

		// search
        int n = str.size(), center = 0, mx = 0;
		vector<int> palin(n, 0);

		for (int i = 1; i < n - 1; i++)
		{
			palin[i] = mx > i ? min(palin[2 * center - i], mx - i) : 1;

			while (str[i + palin[i]] == str[i - palin[i]]) palin[i]++;
			
			if (i + palin[i] > mx)
			{
				mx = i + palin[i];
				center = i;
			}
		}

		// return
		int max = INT_MIN;
		int index = 2;
		for (int i = 2; i < str.size() - 1; i++)
		{
			if (palin[i] > max)
			{
				max = palin[i];
				index = i;
			}
		}

		return s.substr((index - max) / 2, max - 1);
	}
};

// dp
class Solution
{
public:
	string longestPalindrome(string s)
	{
		int len = s.size();
		if (len < 2) return s;

		vector<vector<bool>> dp(len, vector<bool>(len, false));

		int max_idx = 0;
		int max_len = 1;

		dp[0][1] = s[0] == s[1];

		for (int i = 2; i < len; i++)
		{
			dp[i][i] = true;
			dp[i][i - 1] = true;
			dp[i - 1][i] = s[i] == s[i - 1];
			dp[i - 2][i] = s[i] == s[i - 2];

			for (int j = 0; j < i; j++)
			{
				if (dp[j + 1][i - 1] && s[j] == s[i])
				{
					dp[j][i] = true;
					if (i - j + 1 > max_len)
					{
						max_idx = j;
						max_len = i - j + 1;
					}
				}
			}
		}
		
		return string(s, max_idx, max_len);
	}
};

int main()
{
	Solution solution;

	string input;

	while (cin >> input)
	{
		cout << solution.longestPalindrome(input) << endl;
	}

	while (getchar());

	return 0;
}