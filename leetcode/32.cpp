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
	int longestValidParentheses(string s)
	{
		int ret = 0;
		int len = s.length();

		stack<int> stk;
		int bgn = -1;

		for (int i = 0; i < len; i++)
		{
			if (s[i] == '(')
			{
				stk.push(i);
			}
			else
			{
				if (!stk.empty())
				{
					stk.pop();
					ret = stk.empty() ? max(ret, i - bgn) : max(ret, i - stk.top());
				}
				else
				{
					bgn = i;
				}
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	solution.longestValidParentheses("()");

	while (getchar());

	return 0;
}