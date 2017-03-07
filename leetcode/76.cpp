#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>	
#include <map>
#include <queue>

using namespace std;

class Solution
{
public:
	string minWindow(string s, string t)
	{
		int cnts[CHAR_MAX] = { 0 };
		int len = INT_MAX, idx = -1, total = 0;

		for (auto c : t)
		{
			total += cnts[c] == 0;
			cnts[c]++;
		}
		for (int i = 0, j = 0; i < s.size(); i++)
		{
			cnts[s[i]]--;
			if (cnts[s[i]] == 0)
			{
				total--;
				if (total == 0)
				{
					while (cnts[s[j]] < 0)
					{
						cnts[s[j++]]++;
					}
					if (i - j < len)
					{
						len = i - j;
						idx = j;
					}
					cnts[s[j++]]++;
					total++;
				}
			}
		}
		return idx == -1 ? "" : s.substr(idx, len + 1);
	}
};

int main()
{
	while (getchar());

	return 0;
}