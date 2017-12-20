#include <algorithm>
#include <array>
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
#define FO(x, n) for (int x = 0; x < n; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define fi first
#define se second
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7f7f7f7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 10010;
int N, dp[MAXN][3];
vector<int> edges[MAXN];

void dfs(int par, int u)
{
    if (par != -1 && edges[u].size() == 1)
    {
        dp[u][0] = 1, dp[u][1] = MAXN, dp[u][2] = 0;
        return;
    }
    dp[u][0] = 1;
    dp[u][1] = MAXN;
    dp[u][2] = 0;
    for (int i = 0; i < edges[u].size(); ++i)
    {
        int v = edges[u][i];
        if (v == par)
            continue;
        dfs(u, v);
        dp[u][0] += min(dp[v][2], dp[v][0]);
        dp[u][2] += dp[v][1];
    }
    for (int i = 0; i < edges[u].size(); ++i)
    {
        int v = edges[u][i];
        if (v == par)
            continue;
        dp[u][1] = min(dp[u][1], dp[u][2] - dp[v][1] + dp[v][0]);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N)
    {
        FO (i, N + 1)
            edges[i].clear();
        FO (i, N - 1)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        dfs(-1, 1);
        printf("%d\n", min(dp[1][0], dp[1][1]));
        cin >> N;
    }
    return 0;
}
