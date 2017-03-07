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
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
	{
		int ret = 1;
		queue<string> bfs;
		queue<string> tmp;
		bfs.push(beginWord);

		while (!bfs.empty() && !wordList.empty())
		{
			ret++;
			while (!bfs.empty())
			{
				string str = bfs.front();
				bfs.pop();

				for (int i = 0; i < str.size(); i++)
				{
					char old = str[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (c == old) continue;

						str[i] = c;
						if (str == endWord)
						{
							return ret;
						}
						if (wordList.find(str) != wordList.end())
						{
							tmp.push(str);
							wordList.erase(str);
						}
						str[i] = old;
					}
				}
			}
			swap(bfs, tmp);
		}

		return 0;
	}
};


int main()
{
	Solution solution;

	unordered_set<string> wordList = { "hot","dot","dog","lot","log" };
	string bgn = "hit";
	string end = "cog";

	cout << solution.ladderLength(bgn, end, wordList) << endl;

	while (getchar());

	return 0;
}