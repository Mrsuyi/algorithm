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
	vector<string> generateParenthesis(int n)
	{
		vector<string> ret;
		append(ret, "", n, n);
		return ret;
	}

	void append(vector<string>& ret, string prefix, int l, int r)
	{
		if (l == 0)
		{
			ret.push_back(prefix + string(r, ')'));
			return;
		}
		append(ret, prefix + '(', l - 1, r);
		if (l < r)
		{ 
			append(ret, prefix + ')', l, r - 1);
		}
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}