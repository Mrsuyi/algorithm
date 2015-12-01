#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int countPrimes(int n)
	{
		bool* prime = new bool[n];
		memset(prime, 1, sizeof(bool) * n);

		for (int i = 2; i * i < n; i++)
		{
			if (!prime[i]) continue;

			for (int j = i * i; j < n; j += i)
			{
				prime[j] = false;
			}
		}

		int ret = 0;

		for (int i = 2; i < n; i++) { ret += prime[i]; }

		return ret;
	}
};

int main()
{
	Solution solution;

	while (getchar());

	return 0;
}