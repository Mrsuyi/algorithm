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
	typedef long long ll;

public:
	string fractionToDecimal(int numerator, int denominator)
	{
		ll dvd = llabs(numerator);
		ll dsr = llabs(denominator);
		ll integer = dvd / dsr;
		ll decimal = dvd % dsr;

		string ret = (numerator >> 31) ^ (denominator >> 31) && dvd ? "-" : "";
		ret += to_string(integer);

		if (decimal)
		{
			ret += '.';
			dvd = decimal;
			unordered_map<ll, int> map;
			int i = ret.length();
			map[dvd] = i;

			while (true)
			{
				dvd *= 10;
				ret += ('0' + dvd / dsr);
				dvd = dvd % dsr;

				if (dvd == 0)
				{
					return ret;
				}
				else if (map[dvd])
				{
					ret.insert(ret.begin() + map[dvd], '(');
					ret += ')';
					return ret;
				}
				else
				{
					map[dvd] = ++i;
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