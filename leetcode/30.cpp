#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		int ws = words.size();
		int ls = s.length();
		
		if (ls == 0 || ws == 0) return{};

		int lw = words[0].length();

		unordered_map<string, int> map;
		for (auto word : words)
		{
			map[word]++;
		}

		vector<int> ret;
		for (int i = 0; i < lw; i++)
		{
			unordered_map<string, int> tmp;
			
			for (int idx = i, cnt = 0; idx <= ls - (ws - cnt) * lw; idx += lw)
			{
				auto w = map.find(s.substr(idx, lw));

				if (w == map.end())
				{
					tmp.clear();
					cnt = 0;
				}
				else
				{
					tmp[w->first]++;
					cnt++;

					if (tmp[w->first] > map[w->first])
					{
						string pre;
						do
						{
							pre = s.substr(idx - (cnt - 1) * lw, lw);
							tmp[pre]--;
							cnt--;
						}
						while (pre != w->first);
					}

					if (cnt == ws)
					{
						ret.push_back(idx - (ws - 1) * lw);
						tmp[s.substr(idx - (ws - 1) * lw, lw)]--;
						cnt--;
					}
				}
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	vector<string> words = { "bar", "foo", "the" };
	string input = "barfoofoobarthefoobarman";

	solution.findSubstring(input, words);

	while (getchar());

	return 0;
}