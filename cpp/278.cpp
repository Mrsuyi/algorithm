#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
	{
		long long left = 1, right = n, mid = (left + right) / 2;

		while (mid != left)
		{
			if (isBadVersion(mid))
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
			mid = (left + right) / 2;
		}
		
		while (!isBadVersion(mid)) { mid++; };

		return mid;
    }
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}