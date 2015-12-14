#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
private:
	typedef long long llong;

	inline llong absolute(llong a)
	{
		llong mask = a >> 63;
		return (a + mask) ^ mask;
	}

public:
	string fractionToDecimal(int numerator, int denominator)
	{
		string ret;

		bool minus = (numerator >> 31) ^ (denominator >> 31);
		llong _div = absolute(numerator);
		llong div_ = absolute(denominator);

		llong integer = (llong)_div / (llong)div_;
		llong decimal = (llong)_div % (llong)div_;

		// integer
		if (minus && (integer || decimal)) ret += '-';
		ret += to_string(integer);

		// decimal
		if (decimal)
		{
			ret += '.';
			_div = decimal;
			unordered_map<llong, int> map;
			int i = ret.length();
			map[_div] = i;

			while (true)
			{
				_div *= 10;
				ret += ('0' + _div / div_);
				_div = _div % div_;

				if (_div == 0)
				{
					return ret;
				}
				else if (map[_div])
				{
					ret.insert(ret.begin() + map[_div], '(');
					ret += ')';
					return ret;
				}
				else
				{
					map[_div] = ++i;
				}
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}