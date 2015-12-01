#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t ret = 0UL;

		for (int i = 0; i < 32; i++)
		{
			ret = ret << 1;
			ret += (n >> i) & 1UL;
		}

		return ret;
	}
};

int main()
{
	Solution solution;

	uint32_t input;

	while (cin >> input)
	{
		cout << solution.reverseBits(input) << endl;
	}

	while (getchar());

	return 0;
}