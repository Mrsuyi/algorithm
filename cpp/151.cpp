#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	void reverseWords(string &s)
	{
		stack<string> words;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (s[i] != ' ')
			{
				int bgn = i++;
				while (i < len && s[i] != ' ') i++;
				words.push(s.substr(bgn, i - bgn));
			}
		}

		string ret;
		while (!words.empty())
		{
			ret += words.top() + ' ';
			words.pop();
		}
		if (ret.length() > 0) ret.pop_back();

		s = ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}