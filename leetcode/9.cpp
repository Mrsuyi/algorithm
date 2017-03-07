#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0)  return false;
		if (x < 10) return true;

		int div = 1000000000;
		while (div > x) { div /= 10; }

		while (div >= 10)
		{
			if (x / div != x % 10) return false;

			x %= div;
			x /= 10;
			div /= 100;
		}

		return true;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}