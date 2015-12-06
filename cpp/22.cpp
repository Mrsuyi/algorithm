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
	vector<string> ret;

	vector<string> generateParenthesis(int n)
	{
		ret.clear();

		append("", n, n);
		
		return ret;
	}

	void append(string prefix, int l, int r)
	{
		if (l == 0)
		{
			prefix += string(r, ')');
			ret.push_back(prefix);
			return;
		}

		append(prefix + '(', l - 1, r);

		if (l < r)
		{
			append(prefix + ')', l, r - 1);
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}