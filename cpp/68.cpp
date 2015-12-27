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
	vector<string> fullJustify(vector<string>& words, int maxWidth)
	{
		vector<string> ret;
		vector<string> tmp;
		int len = 0;

		for (auto str : words)
		{
			if (str.size() + len > maxWidth)
			{
				ret.push_back(justify(tmp, len - tmp.size(), maxWidth));
				tmp.clear();
				len = 0;
			}
			tmp.push_back(str);
			len += str.size() + 1;
		}
		string lst;
		for (auto str : tmp)
		{
			lst += str + ' ';
		}
		lst.pop_back();
		ret.push_back(lst + string(maxWidth - lst.size(), ' '));

		return ret;
	}

	string justify(vector<string>& words, int len, int max)
	{
		int cnt = words.size();
		if (cnt == 1) { return words[0] + string(max - len, ' '); }

		string ret;
		int each = (max - len) / (cnt - 1);
		int more = (max - len) % (cnt - 1);

		for (int i = 0; i < cnt - 1; i++)
		{
			ret += words[i] + string(each + (more-- > 0), ' ');
		}
		
		return ret + words[cnt - 1];
	}
};

int main()
{
	Solution solution;
	vector<string> words = { "" };
	solution.fullJustify(words, 0);

	while (getchar());

	return 0;
}