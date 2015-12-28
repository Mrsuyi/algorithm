#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Rabin-Karp
class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		int l1 = haystack.size();
		int l2 = needle.size();
		if (l1 < l2) return -1;

		int n = 0, k = 0, h = 1;
		for (int i = 0; i < l2 - 1; i++)
		{
			h = (h * CHAR_MAX) % INT_MAX;
		}
		for (int i = 0; i < l2; i++)
		{
			n = (n * CHAR_MAX + haystack[i]) % INT_MAX;
			k = (k * CHAR_MAX + needle[i]) % INT_MAX;
		}

		if (n == k && cmp(haystack, needle, l2 - 1)) return 0;

		for (int i = l2; i < l1; i++)
		{
			n = ((n - haystack[i - l2] * h) * CHAR_MAX + haystack[i]) % INT_MAX;
			if (n == k && cmp(haystack, needle, i)) return i - l2 + 1;
		}
		return -1;
	}

	bool cmp(string& haystack, string& needle, int idx)
	{
		for (int i = needle.size() - 1; i >= 0; i--)
		{
			if (haystack[idx--] != needle[i]) return false;
		}
		return true;
	}
};

// KMP
class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		int l1 = haystack.length();
		int l2 = needle.length();
		vector<int> prefix(l2, 0);

		for (int i = 1; i < l2; i++)
		{
			int j = i;
			do
			{
				j = prefix[j - 1];
				if (needle[i] == needle[j])
				{
					prefix[i] = j + 1;
					break;
				}
			}
			while (j);
		}

		for (int i = 0, j = 0; i < l1; i++)
		{
			if (needle[j] == haystack[i])
			{
				j++;
				if (j == l2) return i - l2 + 1;
			}
			else
			{
				while (j > 0)
				{
					j = prefix[j - 1];
					if (needle[j] == haystack[i])
					{
						j++;
						break;
					}
				}
			}
		}
		return (l2 == 0) - 1;
	}
};


int main()
{
	Solution solution;

	string haystack;
	string needle;

	cin >> haystack;
	cin >> needle;

	cout << solution.strStr(haystack, needle) << endl;

	while (getchar());

	return 0;
}