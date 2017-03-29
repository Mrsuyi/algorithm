#include <iostream>
using namespace std;

long long dp[2002] = {0};

int main()
{
	for (int i = 0; i <= 2000; ++i)
		dp[i] = 0;
	dp[0] = 1;

	for (int i = 1; i <= 17; ++i)
	{
		for (int j = 0; j <= 2000; ++j)
		{
			int nxt = j + i * i;
			if (nxt <= 2000)
				dp[nxt] = (dp[nxt] + dp[j]) % 1000000009;
		}
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int num;
		cin >> num;
		cout << dp[num] << endl;
	}

	return 0;
}