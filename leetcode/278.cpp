#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

bool isBadVersion(int version);

class Solution
{
public:
	int firstBadVersion(int n)
	{
		int l = 1, r = n, mid;

		while (l < r)
		{
			mid = l + (r - l) / 2;

			if (isBadVersion(mid))
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		return l;
	}
};

int main()
{
	while (getchar());

	return 0;
}