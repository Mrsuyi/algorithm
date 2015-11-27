#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	int myAtoi(string str) 
	{
		bool positive = true;
		double val = 0;

		if (str.length() == 0) return 0;

		int i = 0;

		// eliminate whitespace
		while (str[i] == ' ') { i++; }
		
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
			positive = false;
			i++;
		}

		// first digit
		while (i < str.length() && str[i] >= '0' && str[i] <= '9')
		{
			val = val * 10 + (str[i++] - '0');
		}

		val = positive ? val : -val;

		     if (val > INT_MAX) return INT_MAX;
		else if (val < INT_MIN) return INT_MIN;
		else                    return val;
	}
};

int main()
{
	Solution solution;

	string input;

	while (cin >> input)
	{
		cout << solution.myAtoi(input) << endl;
	}

	while (getchar());

	return 0;
}