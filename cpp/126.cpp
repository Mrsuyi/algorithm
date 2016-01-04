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
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
	{
		wordList.insert(endWord);
		wordList.erase(beginWord);
		unordered_map<string, vector<vector<string>>> ladders;
		ladders[beginWord] = { { beginWord } };
		queue<string> q;
		q.push(beginWord);

		while (!q.empty())
		{
			unordered_set<string> nxt;
			int cnt = q.size();

			for (int i = 0; i < cnt; i++)
			{
				string str = q.front();

				for (int j = 0; j < str.size(); j++)
				{
					char tmp = str[j];

					for (char c = 'a'; c <= 'z'; c++)
					{
						if (str[j] == c) continue;
						str[j] = c;

						if (wordList.find(str) != wordList.end())
						{
							for (auto ladder : ladders[q.front()])
							{
								ladder.push_back(str);
								ladders[str].push_back(ladder);
							}
							nxt.insert(str);
						}
					}
					str[j] = tmp;
				}
				q.pop();
			}

			if (ladders[endWord].size() != 0) break;

			for (auto& str : nxt)
			{
				wordList.erase(str);
				q.push(str);
			}
		}

		return ladders[endWord];
	}
};

//https://leetcode.com/discuss/60557/the-fastest-c-solution-56ms

int main()
{
	Solution solution;

	unordered_set<string> words = { "a", "b", "c" };
	solution.findLadders("a", "c", words);

	while (getchar());

	return 0;
}