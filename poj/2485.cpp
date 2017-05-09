#include <climits>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FO(i, n) for (int i = 0; i < n; ++i)
#define RFO(i, n) for (int i = n - 1; i >= 0; --i)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }
const int INF = 0x07070707;

int dist[510][510];
int dist2[510];
bool in[510];

int main()
{
	int T;
	cin >> T;
	FO (t, T)
	{
		int N;
		cin >> N;
		memset(dist, 0, sizeof(dist));
		memset(in, 0, sizeof(in));
		FO (i, N) FO (j, N)
			cin >> dist[i][j];
		FO (i, N)
			dist2[i] = dist[i][0];
		in[0] = true;
		int res = INT_MIN;
		FO (e, N - 1)
		{
			int mind = INT_MAX, v;
			FO (i, N)
				if (!in[i] && dist2[i] < mind)
				{
					mind = dist2[i];
					v = i;
				}
			in[v] = true;
			res = max(res, mind);
			FO (i, N)
				dist2[i] = min(dist2[i], dist[i][v]);
		}
		printf("%d\n", res);
	}
	return 0;
}