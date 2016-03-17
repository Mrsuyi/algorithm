#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

// kmp
class Solution
{
public:
	string shortestPalindrome(string s)
	{
		string rev = s;
		reverse(rev.begin(), rev.end());
		string kmp = s + '#' + rev;

		int len = kmp.size();

		vector<int> common(len, 0);

		for (int i = 1; i < len; i++)
		{
			for (int n = i; n != 0;)
			{
				int k = common[n - 1];

				if (kmp[i] == kmp[k])
				{
					common[i] = k + 1;
					break;
				}
				else
				{
					n = k;
				}
			}
		}
		
		string prefix = s.substr(common[len - 1]);
		reverse(prefix.begin(), prefix.end());
		return prefix + s;
	}
};


/// manacher
class Solution
{
public:
	string shortestPalindrome(string s)
	{
		int len = s.size();
		if (len == 0) return "";

		string str = "^";
		for (char c : s)
		{
			str += '#';
			str += c;
		}
		str += "#$";

		len = str.size() - 1;
		vector<int> radius(len, 1);
		for (int i = 2, idx = 0, mx = 0; i < len; i++)
		{
			int n = i < mx ? min(radius[2 * idx - i], mx - i) : 1;

			while (str[i + n] == str[i - n]) { n++; }

			radius[i] = n;

			if (i + n > mx)
			{
				idx = i;
				mx = i + n;
			}
		}

		int palin = 1;
		for (int i = 2; i < len; i++)
		{
			if (i == radius[i])
			{
				palin = i - 1;
			}
		}

		string rev = s.substr(palin);
		reverse(rev.begin(), rev.end());
		return rev + s;
	}
};


int main()
{
	while (getchar());

	return 0;
}