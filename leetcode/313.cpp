#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
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
	int nthSuperUglyNumber(int n, vector<int>& primes)
	{
		int len = primes.size();

		vector<int> nums = { 1 };
		vector<int> idxs(len, 0);
		while (--n)
		{
			int min = INT_MAX;
			for (int i = 0; i < len; i++)
			{
				int m = nums[idxs[i]] * primes[i];
				if (m < min) min = m;
			}
			nums.push_back(min);
			
			for (int i = 0; i < len; i++)
			{
				if (min == nums[idxs[i]] * primes[i]) idxs[i]++;
			}
		}

		return nums.back();
	}
};

int main()
{
	while (getchar());

	return 0;
}