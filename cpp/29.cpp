#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	typedef long long LL;

	int divide(int dividend, int divisor)
	{
		if (divisor == 0) return INT_MAX;

		LL ret = 0;
		LL num = abs((LL)dividend);
		LL div = abs((LL)divisor);

		while (num >= div)
		{
			int i = 0;
			while ((div << i) <= num) { i++; }
			num -= div << --i;
			ret += 1UL << i;
		}

		return (dividend >> 31) ^ (divisor >> 31) ?
			   -ret : (ret > INT_MAX ? INT_MAX : ret);
	}
};

int main()
{
	Solution solution;
	solution.divide(INT_MIN, -1);

	while (getchar());

	return 0;
}