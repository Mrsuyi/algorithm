#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

#include <ctime>

using namespace std;

inline int max(const int a, const int b) { return a > b ? a : b; };
inline int min(const int a, const int b) { return a < b ? a : b; };

class Solution
{
public:
	// Manacher
	string longestPalindrome(string s)
	{
		const int len = s.length();

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
			// derive from exist palin
			palin[i] = mx > i ? min(palin[2 * center - i], mx - i) : 1;

			// expand
			while (str[i + palin[i]] == str[i - palin[i]]) palin[i]++;
			
			// push center forward
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

	string longestPalindrome(string s)
	{
		if (s.size() <= 2)
		{
			return s;
		}

		int max_l = 0;
		int max_r = 0;
		int max_len = 1;

		// dp
		bool** palin = new bool*[s.size()];
		for (int i = 0; i < s.size(); i++)
		{
			palin[i] = new bool[s.size()];
			memset(palin[i], false, sizeof(bool) * s.size());
		}

		// init dp
		palin[0][1] = s[0] == s[1];

		for (int i = 2; i < s.size(); i++)
		{
			palin[i][i]		= true;
			palin[i][i - 1] = true;
			palin[i - 1][i] = s[i] == s[i - 1];
			palin[i - 2][i] = s[i] == s[i - 2];

			for (int j = 0; j < i; j++)
			{
				if (palin[j + 1][i - 1] && s[j] == s[i])
				{
					palin[j][i] = true;
					int len = i - j + 1;
					if (len > max_len)
					{
						max_l = j;
						max_r = i;
						max_len = len;
					}
				}
			}
		}

		return string(s, max_l, max_len);
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