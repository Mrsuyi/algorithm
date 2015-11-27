#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:

	int divisor[9] =
	{
		1000000000,
		100000000,
		10000000,
		1000000,
		100000,
		10000,
		1000,
		100,
		10
	};

	bool isPalindrome(int x)
	{
		if (x < 0)  return false;
		if (x < 10) return true;

		int i = 0;

		while (x < divisor[i]) { i++; }

		while (i < 9)
		{
			int left  = x / divisor[i];
			int right = x % 10;

			if (left != right)
			{
				return false;
			}

			x -= left * divisor[i];
			x /= 10;
			i += 2;
		}

		return true;
	}
};

int main()
{
	Solution solution;

	int input;

	while (cin >> input)
	{
		cout << solution.isPalindrome(input) << endl;
	}

	while (getchar());

	return 0;
}