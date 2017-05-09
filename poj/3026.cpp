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

string matrix[200];
int dp[200][200];
vector<pii> bfs[30000];
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
	int Ca;
	cin >> Ca;
	FO (ca, Ca)
	{
		int m, n;
		cin >> n >> m;
		getline(cin, matrix[0]);
		FO (i, m)
			getline(cin, matrix[i]);
		FO (i, m * n)
			bfs[i].clear();
		FO (i, m) FO (j, n)
			dp[i][j] = INT_MAX;
		int initx, inity;
		FO (i, m) FO (j, n)
			if (matrix[i][j] == 'S')
			{
				initx = i;
				inity = j;
				goto begin;
			}
	begin:;
		int res = 0;
		dp[initx][inity] = 1;
		bfs[1].push_back(pii(initx, inity));
		int maxs = 1;
		while (!bfs[1].empty())
		{
			bool ok = false;
			for (int step = 1; step <= maxs; ++step)
			{
				FO (i, bfs[step].size())
				{
					int x = bfs[step][i].fi;
					int y = bfs[step][i].se;
					FO (j, 4)
					{
						int p = x + dirs[j][0];
						int q = y + dirs[j][1];
						if (!ok && matrix[p][q] == 'A' && dp[p][q] == INT_MAX)
						{
							res += step;
							dp[p][q] = 1;
							bfs[1].push_back(pii(p, q));
							ok = true;
						}
						if (matrix[p][q] == ' ' && step + 1 < dp[p][q])
						{
							dp[p][q] = step + 1;
							maxs = max(step + 1, maxs);
							bfs[step + 1].push_back(pii(p, q));
						}
					}
				}
				if (!ok)
					bfs[step].clear();
			}
		next:;
		}
	end:;
		printf("%d\n", res);
	}
	system("PAUSE");
	return 0;
}