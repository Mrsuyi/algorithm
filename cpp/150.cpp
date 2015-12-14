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
	int evalRPN(vector<string>& tokens)
	{
		stack<int> operands;
		stack<char> operators;

		for (string& str : tokens)
		{
			char c = str[0];
			int len = str.length();
			if (len == 1 && (c == '+' || c == '-' || c == '*' || c == '/'))
			{
				int r = operands.top();
				operands.pop();
				int l = operands.top();
				operands.pop();

				switch (c)
				{
					case '+': operands.push(l + r); break;
					case '-': operands.push(l - r); break;
					case '*': operands.push(l * r); break;
					case '/': operands.push(l / r); break;
				}
			}
			else
			{
				int i = 0;
				int n = 0;
				bool minus = false;
				if (c == '-')
				{
					i++;
					minus = true;
				}
				for (; i < len; i++)
				{
					n = 10 * n + (str[i] - '0');
				}
				operands.push(minus ? -n : n);
			}
		}

		return operands.top();
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}