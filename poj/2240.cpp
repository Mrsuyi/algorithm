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

map<string, int> names;
double edge[35][35];

int main()
{
	int t = 0;
	int N;
	while (cin >> N)
	{
		++t;
		memset(edge, 0, sizeof(edge));
		if (N == 0)
			break;
		FOR (i, N)
		{
			string name;
			cin >> name;
			names[name] = i;
		}
		int M;
		cin >> M;
		FOR (i, M)
		{
			string src, dst;
			double r;
			cin >> src >> r >> dst;
			edge[names[src]][names[dst]] = r;
		}
		FOR (k, N) FOR (i, N) FOR (j, N)
			edge[i][j] = max(edge[i][j], edge[i][k] * edge[k][j]);
		FOR (i, N) FOR (j, N)
			if (edge[i][j] * edge[j][i] > 1)
			{
				printf("Case %d: Yes\n", t);
				goto end;
			}
		printf("Case %d: No\n", t);
		end:;
	}
	return 0;
}