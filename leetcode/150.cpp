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
		stack<int> stk;

		for (auto& str : tokens)
		{
			if (str.size() == 1 && str[0] < '0')
			{
				int b = stk.top();
				stk.pop();
				int a = stk.top();
				stk.pop();

				switch (str[0])
				{
				case '+': stk.push(a + b); break;
				case '-': stk.push(a - b); break;
				case '*': stk.push(a * b); break;
				case '/': stk.push(a / b); break;
				}
			}
			else
			{
				stk.push(stoi(str));
			}
		}

		return stk.top();
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}