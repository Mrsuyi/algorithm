#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:

	int romanToInt(string s)
	{
		int ret = 0;
		int pre = INT_MAX;
		int cur = 0;

		for (int i = 0; i < s.length(); i++)
		{
			switch (s[i])
			{
			case 'I': cur = 1;    break;
			case 'V': cur = 5;    break;
			case 'X': cur = 10;   break;
			case 'L': cur = 50;   break;
			case 'C': cur = 100;  break;
			case 'D': cur = 500;  break;
			case 'M': cur = 1000; break;
			}

			if (cur > pre)
			{
				ret += cur - 2 * pre;
			}
			else
			{
				ret += cur;
			}

			pre = cur;
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	string input;

	while (cin >> input)
	{
		cout << solution.romanToInt(input) << endl;
	}

	while (getchar());

	return 0;
}