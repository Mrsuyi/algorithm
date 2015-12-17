#include <iostream>
#include <vector>
#include <stack>
#include <string>
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
	int calculate(string s)
	{
		int len = s.length();
		if (len == 0) return 0;

		int ret = 0;
		stack<int> sign;
		sign.push(1);
		s.push_back('$');
		len++;
		int last = 1;
		int num = 0;
		
		for (int i = 0; i < len; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = 10 * num + s[i] - '0';
			}
			else if (s[i] == '(')
			{
				sign.push(sign.top() * last);
				last = 1;
			}
			else if (s[i] == ')')
			{
				ret += sign.top() * last * num;
				num = 0;
				sign.pop();
			}
			else if (s[i] != ' ')
			{
				ret += sign.top() * last * num;
				num = 0;
				last = s[i] == '+' ? 1 : -1;
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	cout << solution.calculate("1-(5)") << endl;

	while (getchar());

	return 0;
}