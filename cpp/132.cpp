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

class Solution
{
public:
	int minCut(string s)
	{
		vector<bool> palin(s.size());
		vector<int> cut(s.size() + 1, INT_MAX);

		cut[0] = -1;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (s[i] == s[j] && (i - j <= 2 || palin[j + 1]))
				{
					palin[j] = true;
					cut[i + 1] = min(cut[i + 1], cut[j] + 1);
				}
				else
				{
					palin[j] = false;
				}
			}
		}
		return cut[s.size()];
	}
};

int main()
{
	while (getchar());

	return 0;
}