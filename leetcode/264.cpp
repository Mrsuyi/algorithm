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
	int nthUglyNumber(int n)
	{
		vector<int> ugly = { 1 };
		int i2(0), i3(0), i5(0);

		while (--n)
		{
			int m2 = ugly[i2] * 2;
			int m3 = ugly[i3] * 3;
			int m5 = ugly[i5] * 5;
			
			int m = min(m2, min(m3, m5));
			ugly.push_back(m);

			if (m == m2) i2++;
			if (m == m3) i3++;
			if (m == m5) i5++;
		}

		return ugly.back();
	}
};

int main()
{
	Solution solution;

	solution.nthUglyNumber(23);

	while (getchar());

	return 0;
}