#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		int len = strs.size();
		if (len == 0) return "";
		if (len == 1) return strs[0];
		if (strs[0].size() == 0) return "";

		string ret;
		for (int i = 0;; i++)
		{
			char chr = strs[0][i];
			for (int j = 1; j < len; j++)
			{
				if (strs[j].size() == i || strs[j][i] != chr)
				{
					return ret;
				}
			}
			ret += chr;
		}
	}
};