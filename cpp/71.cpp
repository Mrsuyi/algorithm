#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		vector<string> secs;

		// divide
		int i = 1;
		int len = path.length();
		while (i < len)
		{
			string sec;
			while (i < len && path[i] != '/') { sec += path[i++]; }

			if (sec == "..")
			{
				if (!secs.empty()) secs.pop_back();
			}
			else if (!sec.empty() && sec != ".")
			{
				secs.push_back(sec);
			}

			i++;
		}

		// make up
		string ret;
		for (int i = 0; i < secs.size(); i++)
		{
			ret += '/' + secs[i];
		}
		return ret.empty() ? "/" : ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}