#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> stk;
		for (int i = 0; i < s.length(); i++)
		{
			switch (s[i])
			{
			case ')': if (!stk.empty() && stk.top() == '(') stk.pop(); else return false; break;
			case ']': if (!stk.empty() && stk.top() == '[') stk.pop(); else return false; break;
			case '}': if (!stk.empty() && stk.top() == '{') stk.pop(); else return false; break;
			default: stk.push(s[i]);
			}
		}
		return stk.empty();
	}
};

int main()
{
	while (getchar());

	return 0;
}