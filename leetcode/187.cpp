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
	vector<string> findRepeatedDnaSequences(string s)
	{
		vector<string> ret;
		unordered_map<unsigned, int> map;

		int len = s.length();
		if (len <= 10) return ret;

		// search
		unsigned val = 0;
		for (int i = 0; i < len; i++)
		{
			val <<= 3;
			val |= s[i] & 0x00000007;
			val &= 0x3fffffff;

			if (map[val]++ == 1) ret.push_back(s.substr(i - 9, 10));
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