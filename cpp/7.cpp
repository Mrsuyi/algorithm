#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

using LL = long long;

class Solution
{
public:

	inline LL abs(LL a)
	{
		return (a >> 63) ^ a + (a >> 63);
	}

	int reverse(int x)
	{
		const bool positive = !(x >> 31);

		LL  ret = 0;
		for (LL val = abs(x); val != 0; val /= 10)
		{
			ret = ret * 10 + val % 10;
		}

		     if (ret > 2147483647)  return 0;
		else if (positive == false) return -ret;
		else                        return ret;
	}
};

int main()
{
	Solution solution;

	int input;

	while (cin >> input)
	{
		cout << solution.reverse(input) << endl;
	}

	while (getchar());

	return 0;
}