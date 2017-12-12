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
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7fffff7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 33;
int N;
int pts[MAXN * 3][3];
bool conn[MAXN * 3][MAXN * 3];
int dp[MAXN * 3], in[MAXN * 3];

int dfs(int u)
{
    if (dp[u] != -1)
        return dp[u];
    dp[u] = 0;
    FO (v, 3 * N)
    {
        if (conn[u][v])
            dp[u] = max(dp[u], dfs(v));
    }
    return dp[u] += pts[u][2];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int o = 1; cin >> N && N; ++o)
    {
        FO (i, N)
        {
            int x[3];
            cin >> x[0] >> x[1] >> x[2];
            sort(x, x + 3);
            pts[3 * i][0] = x[1];
            pts[3 * i][1] = x[0];
            pts[3 * i][2] = x[2];
            pts[3 * i + 1][0] = x[2];
            pts[3 * i + 1][1] = x[1];
            pts[3 * i + 1][2] = x[0];
            pts[3 * i + 2][0] = x[2];
            pts[3 * i + 2][1] = x[0];
            pts[3 * i + 2][2] = x[1];
        }
        memset(conn, 0, sizeof(conn));
        memset(in, 0, sizeof(in));
        int res = 0;
        FO (i, 3 * N) FO (j, 3 * N)
            if (pts[i][0] < pts[j][0] && pts[i][1] < pts[j][1])
            {
                conn[j][i] = true;
                ++in[i];
            }
        memset(dp, -1, sizeof(dp));
        FO (i, 3 * N)
        {
            if (in[i])
                continue;
            res = max(res, dfs(i));
        }
        printf("Case %d: maximum height = %d\n", o, res);
    }
    return 0;
}
