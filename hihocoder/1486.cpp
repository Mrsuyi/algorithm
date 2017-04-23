#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int n, m;
		scanf("%d%d", &n, &m);
        vector<int> dp(1 << m, -1);
        dp[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			int v, s, bits = 0;
			scanf("%d%d", &v, &s);
            vector<int> dp2 = dp;
			for (int j = 0; j < s; ++j)
			{
				int bit;
				scanf("%d", &bit);
				bits |= 1 << (bit - 1);
			}
			for (int j = 0; j < (1 << m); ++j)
			{
                if (dp[j] != -1)
					dp2[j ^ bits] = max(dp2[j ^ bits], dp[j] + v);
			}
            swap(dp, dp2);
		}
		printf("%d\n", dp[(1 << m) - 1]);
	}

	return 0;
};