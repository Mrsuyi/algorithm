#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

inline long long absolute(long long n)
{
	const long long mask = n >> 63;
	return (n + mask) ^ mask;
}

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0) return INT_MAX;

		bool minus = (dividend >> 31) ^ (divisor >> 31);
		long long ret = 0;

		long long divd = (long long)dividend;
		long long div = (long long)divisor;

		divd = absolute(divd);
		div = absolute(div);

		int mul_2 = 0;

		while (div < divd)
		{
			div <<= 1;
			mul_2++;
		}

		while (mul_2 >= 0 && divd)
		{
			if (divd >= div)
			{
				divd -= div;
				ret += 1ULL << mul_2;
			}

			div >>= 1;
			mul_2--;
		}

		ret = minus ? -ret : ret;

		return (ret > INT_MAX || ret < INT_MIN) ? INT_MAX : ret;
	}
};

int main()
{
	Solution solution;

	while (true)
	{
		int a, b;
		cin >> a >> b;
		cout << solution.divide(a, b) << endl;
	}

	while (getchar());

	return 0;
}