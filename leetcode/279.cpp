#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
	int numSquares(int n)
	{
		while (n % 4 == 0) n /= 4;

		if (n % 8 == 7) return 4;
		
		for (int a = 0; a * a <= n; a++)
		{
			int b = sqrt(n - a * a);
			if (a * a + b * b == n)
			{
				return !!a + !!b;
			}
		}
		return 3;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}