#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }
const double PI = 3.14159265358;

int dp[1441][2][721];

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int aj, ac;
		cin >> ac >> aj;
		vector<bool> ccan(1441, true), jcan(1441, true);
		for (int i = 0; i < ac; ++i)
		{
			int bgn, end;
			cin >> bgn >> end;
			for (int j = bgn + 1; j <= end; ++j)
				ccan[j] = false;
		}
		for (int i = 0; i < aj; ++i)
		{
			int bgn, end;
			cin >> bgn >> end;
			for (int j = bgn + 1; j <= end; ++j)
				jcan[j] = false;
		}
		int res = INT_MAX;

		memset(dp, 10000, sizeof(dp));
		dp[0][0][0] = 0;
		for (int i = 1; i <= 1440; ++i)
		{
			// c work
			if (ccan[i])
			{
				for (int j = 1; j <= min(720, i); ++j)
				{
					dp[i][0][j] = dp[i - 1][0][j - 1];
					dp[i][0][j] = min(dp[i][0][j], dp[i - 1][1][j - 1] + 1);
				}
			}
			if (jcan[i])
			{
				for (int j = 0; j <= min(720, i); ++j)
				{
					dp[i][1][j] = dp[i - 1][1][j];
					dp[i][1][j] = min(dp[i][1][j], dp[i - 1][0][j] + 1);
				}
			}
		}
		res = dp[1440][0][720];

		memset(dp, 10000, sizeof(dp));
		dp[0][1][0] = 0;
		for (int i = 1; i <= 1440; ++i)
		{
			// c work
			if (ccan[i])
			{
				for (int j = 1; j <= min(720, i); ++j)
				{
					dp[i][0][j] = dp[i - 1][0][j - 1];
					dp[i][0][j] = min(dp[i][0][j], dp[i - 1][1][j - 1] + 1);
				}
			}
			if (jcan[i])
			{
				for (int j = 0; j <= min(720, i); ++j)
				{
					dp[i][1][j] = dp[i - 1][1][j];
					dp[i][1][j] = min(dp[i][1][j], dp[i - 1][0][j] + 1);
				}
			}
		}
		res = min(res, dp[1440][1][720]);

		printf("Case #%d: %d\n", t, res);
	}
	return 0;
};