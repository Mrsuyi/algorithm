#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	bool wordBreak(string s, unordered_set<string>& wordDict)
	{
		int len = s.length();
		vector<bool> can = vector<bool>(len, false);

		for (int i = 0; i < len; i++)
		{
			if (wordDict.find(string(s, 0, i + 1)) != wordDict.end())
			{
				can[i] = true;
			}
			else
			{
				bool flag = false;
				for (int j = i - 1; j >= 0; j--)
				{
					if (can[j] && (wordDict.find(string(s, j + 1, i - j)) != wordDict.end()))
					{
						flag = true;
						break;
					}
				}
				can[i] = flag;
			}
		}

		return can[len - 1];
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}