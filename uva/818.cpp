#include <algorithm>
#include <array>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
# include <tr1/unordered_map>
# include <tr1/unordered_set>
using namespace tr1;
# endif
# else
# include <unordered_map>
# include <unordered_set>
# endif
using namespace std;

#define FO(x, n) for (int x = 0; x < n; ++x)
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;

inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 16;
int N;
bool conn[MAXN][MAXN];
bool open[MAXN];
int vis[MAXN];

bool dfs(int from, int cur, int chain)
{
    vis[cur] = chain;
    int branch = from != -1;
    for (int i = 0; i < N; ++i)
    {
        if (i == from || open[i] || !conn[cur][i])
            continue;
        if (vis[i])
            return false;
        ++branch;
        if (!dfs(cur, i, chain))
            return false;
    }
    return branch < 3;
}

int ok(int stt)
{
    int cnt = 0;
    memset(open, 0, sizeof(open));
    for (int i = 0; i < N; ++i)
    {
        if (stt & (1 << i))
        {
            open[i] = true;
            ++cnt;
        }
    }
    memset(vis, 0, sizeof(vis));
    int chain = 0;
    for (int i = 0; i < N; ++i)
    {
        if (vis[i] || open[i])
            continue;
        ++chain;
        if (!dfs(-1, i, chain))
            return INT_MAX;
    }
    return (chain <= cnt + 1) ? cnt : INT_MAX;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int t = 1; cin >> N && N; ++t)
    {
        memset(conn, 0, sizeof(conn));
        int a, b;
        while (cin >> a >> b && a != -1)
            conn[a - 1][b - 1] = conn[b - 1][a - 1] = true;
        int res = INT_MAX;
        for (int i = 0; i < (1 << N); ++i)
            res = min(res, ok(i));
        printf("Set %d: Minimum links to open is %d\n", t, res);
    }
    return 0;
}