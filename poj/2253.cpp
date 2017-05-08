#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define fi first
#define se second
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define RFOR(i, n) for (int i = n - 1; i >= 0; --i)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int N;
pii pos[220];
double dist[220][220];

int main()
{
	int t = 0;
	while (cin >> N)
	{
		++t;
		if (N == 0)
			break;
		FOR (i, N)
			cin >> pos[i].fi >> pos[i].se;
		FOR (i, N) FOR (j, N)
		{
			double x = pos[i].fi - pos[j].fi;
			double y = pos[i].se - pos[j].se;
			dist[i][j] = dist[j][i] = sqrt(x * x + y * y);
		}
		bool in[220] = {0};
		double dp[220];
		FOR (i, N) dp[i] = INT_MAX;
		dp[0] = 0;
		queue<int> spfa;
		spfa.push(0);
		while (!spfa.empty())
		{
			int u = spfa.front();
			spfa.pop();
			in[u] = false;
			FOR (v, N)
			{
				if (u == v) continue;
				if (max(dp[u], dist[u][v]) < dp[v])
				{
					dp[v] = max(dp[u], dist[u][v]);
					if (!in[v])
					{
						spfa.push(v);
						in[v] = true;
					}
				}
			}
		}
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", t, dp[1]);
	}
	return 0;
}