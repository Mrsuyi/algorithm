#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	const int max = 1 << 14 + 1;
	bool is_prime[max];
	memset(is_prime, 1, max);

	for (int i = 2; i < max; ++i)
	{
		if (!is_prime[i]) continue;
		for (int j = 2; i * j < max; ++j)
			is_prime[i * j] = false;
	}
	
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		
		int res = 0;
		for (int i = 2; i <= n / 2; ++i)
			if (is_prime[i] && is_prime[n - i])
				++res;
		cout << res << endl;
	}

	return 0;
}