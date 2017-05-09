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
const int INF = 0x07070707;

int dist[110][110];

int main()
{
	int N;
	while (cin >> N)
	{
		if (N == 0)
			break;
		memset(dist, INF, sizeof(dist));
		FOR (i, N)
		{
			dist[i][i] = 0;
			int M;
			cin >> M;
			FOR (j, M)
			{
				int v, t;
				cin >> v >> t;
				--v;
				dist[i][v] = t;
			}
		}
		FOR (k, N) FOR (i, N) FOR (j, N)
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int mind = INF, init;
		FOR (i, N)
		{
			int maxd = INT_MIN;
			FOR (j, N)
			{
				if (i == j) continue;
				maxd = max(maxd, dist[i][j]);
			}
			if (maxd != INT_MIN && maxd < mind)
			{
				mind = maxd;
				init = i + 1;
			}
		}
		if (mind == INF)
			printf("disjoint\n");
		else
			printf("%d %d\n", init, mind);
	}

	return 0;
}