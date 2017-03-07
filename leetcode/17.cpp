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
	vector<string> letterCombinations(string digits)
	{
		if (digits.size() == 0) return{};

		vector<string> ret = { "" };
		string map[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		for (auto d : digits)
		{
			vector<string> tmp;
			for (auto str : ret)
			{
				for (auto c : map[d - '2'])
				{
					tmp.push_back(str + c);
				}
			}
			ret = tmp;
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