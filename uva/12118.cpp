#include <algorithm>
#include <cassert>
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

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXV = 1010;
int V, E, T;
vector<int> edges[MAXV];
int cnt[MAXV], vis[MAXV];

int dfs(int u)
{
    int res = cnt[u] & 1;
    vis[u] = true;
    for (int i = 0; i < edges[u].size(); ++i)
    {
        int v = edges[u][i];
        if (vis[v])
            continue;
        res += dfs(v);
    }
    return res;
}

int main()
{
    for (int t = 1; cin >> V >> E >> T; ++t)
    {
        if (V == 0)
            break;
        memset(cnt, 0, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        FO (i, E)
        {
            int u, v;
            cin >> u >> v;
            ++cnt[u];
            ++cnt[v];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        int res = 0;
        for (int i = 1; i <= V; ++i)
        {
            if (vis[i])
                continue;
            res += 1 + max(0, (dfs(i) - 2) / 2);
        }
        printf("Case %d: %d\n", t, (res - 1 + E) * T);
    }
    return 0;
}