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
		s.push_back('$');
		len++;
		char opr_1 = '+'; // + -
		char opr_2 = 0;   // * / 0
		int num = 0;
		int mul = 1;

		for (int i = 0; i < len; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = 10 * num + s[i] - '0';
			}
			else if (s[i] == '*' || s[i] == '/')
			{
				mul = opr_2 == 0 ? num : (opr_2 == '*' ? mul * num : mul / num);
				num = 0;
				opr_2 = s[i];
			}
			else if (s[i] != ' ')
			{
				if (opr_2 != 0)
				{
					mul = opr_2 == '*' ? mul * num : mul / num;
					ret += opr_1 == '+' ? mul : -mul;
					mul = 0;
					opr_2 = 0;
				}
				else
				{
					ret += opr_1 == '+' ? num : -num;
				}
				num = 0;
				opr_1 = s[i];
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	cout << solution.calculate("9/3+5*6/3");

	while (getchar());

	return 0;
}