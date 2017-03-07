#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int titleToNumber(string s)
	{
		int ret = 0;
		for (char c : s)
		{
			ret = ret * 26 + c - 'A' + 1;
		}
		return ret;
	}
};

int main()
{
	while (getchar());

	return 0;
}