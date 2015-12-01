#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int trailingZeroes(int n)
	{
		int ret = 0;
		int div = 5;

		int quo;

		do
		{
			quo = n / div;
			ret += quo;
			div *= 5;
		}
		while (quo >= 5);

		return ret;
	}
};

int main()
{
	Solution solution;

	int input;

	while (cin >> input)
	{
		cout << solution.trailingZeroes(input) << endl;
	}

	while (getchar());

	return 0;
}