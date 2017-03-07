#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool wordPattern(string pattern, string str)
	{
		vector<string> secs;

		// explode
		int bgn = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				secs.push_back(string(str, bgn, i - bgn));
				bgn = i + 1;
				i++;
			}
		}
		secs.push_back(string(str, bgn));

		// check str-num
		if (secs.size() != pattern.size()) return false;

		// check str
		unordered_map<char, string> c_2_s;
		unordered_map<string, char> s_2_c;

		for (int i = 0; i < pattern.size(); i++)
		{
			char c = pattern[i];
			string s = secs[i];

			auto find_c_2_s = c_2_s.find(c);
			if (find_c_2_s != c_2_s.end() && find_c_2_s->second != s)
				return false;
			else
				c_2_s[c] = s;

			auto find_s_2_c = s_2_c.find(s);
			if (find_s_2_c != s_2_c.end() && find_s_2_c->second != c)
				return false;
			else
				s_2_c[s] = c;
		}

		return true;
	}
};

int main()
{
	Solution solution;

	string pattern;
	string input;

	getline(cin, pattern);
	getline(cin, input);

	cout << solution.wordPattern(pattern, input) << endl;

	while (getchar());

	return 0;
}