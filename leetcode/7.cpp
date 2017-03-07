#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>	

using namespace std;

class Solution
{
public:
	typedef long long LL;

	inline LL abs(LL a)
	{
		return (a >> 63) ^ a + (a >> 63);
	}

	int reverse(int x)
	{
		LL ret = 0;
		for (LL val = abs(x); val != 0; val /= 10)
		{
			ret = ret * 10 + val % 10;
		}
		return ret > INT_MAX ? 0 : (x & 0x80000000 ? -ret : ret);
	}
};

int main()
{
	while (getchar());

	return 0;
}