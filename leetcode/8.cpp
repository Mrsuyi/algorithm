#include <iostream>
#include <vector>
#include <string>
#include <algorithm>	

using namespace std;

class Solution
{
public:
	int myAtoi(string str)
	{
		int len = str.length();
		if (len == 0) return 0;

		int i = 0;

		while (str[i] == ' ') { i++; }

		int symbol = 1;

		if (i == str.length())
		{
			return 0;
		}
		else if (str[i] == '+')
		{
			i++;
		}
		else if (str[i] == '-')
		{
			symbol = -1;
			i++;
		}

		double ret = 0;

		while (i < len && str[i] >= '0' && str[i] <= '9')
		{
			ret = ret * 10 + (str[i++] - '0');
		}

		ret = symbol * ret;

		return ret > INT_MAX ? INT_MAX : ret < INT_MIN ? INT_MIN : ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}