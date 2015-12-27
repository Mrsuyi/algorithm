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
	bool isNumber(string s)
	{
		int len = s.length();
		int i = 0;

		while (i < len && s[i] == ' ') { i++; }
		if (i == len) return false;
		if (s[i] == '-' || s[i] == '+') { i++; }

		bool num = false; 
		bool dot = false; 
		bool exp = false;

		for (; i < len; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = true;
			}
			else if (s[i] == '.')
			{
				if (exp || dot) return false;
				dot = true;
			}
			else if (s[i] == 'e')
			{
				if (exp || num == false) return false;
				exp = true;
				num = false;
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				if (s[i - 1] != 'e') return false;
			}
			else
			{
				break;
			}
		}
		while (i < len && s[i] == ' ') { i++; }
		
		return i == len && num;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}