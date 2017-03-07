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
		int cnt = 0;
		while (n)
		{
			cnt += n / 5;
			n /= 5;
		}
		return cnt;
	}
};

int main()
{
	while (getchar());

	return 0;
}