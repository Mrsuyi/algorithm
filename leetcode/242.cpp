#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t)
	{
		int len = s.size();

		if (len != t.size()) return false;

		int c_s[26] = { 0 }, c_t[26] = { 0 };

		for (int i = 0; i < len; i++)
		{
			c_s[s[i] - 'a']++;
			c_t[t[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++)
		{
			if (c_s[i] != c_t[i])
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}