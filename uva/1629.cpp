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
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 23;
int N, M, K;
int dp[MAXN][MAXN][MAXN][MAXN];
int mp[MAXN][MAXN], cnt[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int o = 1; cin >> N >> M >> K; ++o)
    {
        memset(dp, INF, sizeof(dp));
        memset(mp, 0, sizeof(mp));
        memset(cnt, 0, sizeof(cnt));
        FO (k, K)
        {
            int x, y;
            cin >> x >> y;
            mp[x][y] = 1;
        }
        for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + mp[i][j];
        for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        for (int x = 1; x + i - 1 <= N; ++x)
        for (int y = 1; y + j - 1 <= M; ++y)
        {
            int p = x + i - 1;
            int q = y + j - 1;
            int c = cnt[p][q] - cnt[p][y - 1] - cnt[x - 1][q] + cnt[x - 1][y - 1];
            if (c == 0)
                continue;
            if (c == 1)
            {
                dp[x][y][p][q] = 0;
                continue;
            }
            for (int k = x; k < p; ++k)
                dp[x][y][p][q] = min(dp[x][y][p][q], dp[x][y][k][q] + dp[k + 1][y][p][q] + j);
            for (int k = y; k < q; ++k)
                dp[x][y][p][q] = min(dp[x][y][p][q], dp[x][y][p][k] + dp[x][k + 1][p][q] + i);
        }
        printf("Case %d: %d\n", o, dp[1][1][N][M]);
    }
    return 0;
}