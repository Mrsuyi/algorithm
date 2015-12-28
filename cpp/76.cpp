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
		int chrs[128] = { 0 };
		int cnts[128] = { 0 };
		queue<int> idxs;

		int len = INT_MAX, idx = -1, cnt = 0;

		for (auto c : t) { chrs[c]++; }

		for (int i = 0; i < s.size(); i++)
		{
			if (chrs[s[i]])
			{
				if (cnts[s[i]] < chrs[s[i]]) cnt++;
				cnts[s[i]]++;
				idxs.push(i);

				if (cnt == t.size())
				{
					char c = s[idxs.front()];
					while (cnts[c] > chrs[c])
					{
						idxs.pop();
						cnts[c]--;
						c = s[idxs.front()];
					}

					int l = i - idxs.front() + 1;
					if (l < len)
					{
						len = l;
						idx = idxs.front();
					}

					do
					{
						c = s[idxs.front()];
						cnts[c]--;
						idxs.pop();
					}
					while (cnts[c] >= chrs[c]);
					cnt--;
				}
			}
		}
		return idx == -1 ? "" : s.substr(idx, len);
	}
};

int main()
{
	Solution solution;

	solution.minWindow("bba", "ab");

	while (getchar());

	return 0;
}