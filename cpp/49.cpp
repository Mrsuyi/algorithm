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
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> map;

		for (string& str : strs)
		{
			string sorted = str;
			sort(sorted.begin(), sorted.end());
			map[sorted].push_back(str);
		}

		vector<vector<string>> ret;
		for (auto& set : map)
		{
			sort(set.second.begin(), set.second.end());
			ret.push_back(set.second);
		}
		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}