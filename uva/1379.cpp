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
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 105, MAXM = 33, MAXG = 220;
int N, M, G;
pii ps[MAXG][MAXG];
int gs[MAXG];
int dp[2][6][6][6][6];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    scanf("%d", &O);
    FO (o, O)
    {
        scanf("%d %d %d", &N, &M, &G);
        G += 10;
        memset(ps, 0, sizeof(ps));
        for (int i = 1; i <= M; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                scanf("%d", &ps[i][j].first);
                ps[i][j].second = j;
            }
            sort(ps[i] + 1, ps[i] + 1 + N, greater<pii>());
        }
        FO (i, G)
            scanf("%d", &gs[i]);
        int K = 6, res = 0;
        memset(dp, 0, sizeof(dp));
        FO (i, G)
        {
            int cur = i & 1, nxt = !cur;
            memset(dp[nxt], 0, sizeof(dp[nxt]));
            FO (a, K) FO (b, K) FO (c, K) FO (d, K)
            {
                if (gs[i] == 0)
                {
                    dp[nxt][b][c][d][0] = max(dp[nxt][b][c][d][0], dp[cur][a][b][c][d]);
                    res = max(res, dp[nxt][b][c][d][0]);
                    continue;
                }
                for (int k = 1; k < K; ++k)
                {
                    if (i > 0 && ps[gs[i]][k].second == ps[gs[i - 1]][d].second ||
                        i > 1 && ps[gs[i]][k].second == ps[gs[i - 2]][c].second ||
                        i > 2 && ps[gs[i]][k].second == ps[gs[i - 3]][b].second ||
                        i > 3 && ps[gs[i]][k].second == ps[gs[i - 4]][a].second)
                        continue;
                    dp[nxt][b][c][d][k] = max(dp[nxt][b][c][d][k], dp[cur][a][b][c][d] + ps[gs[i]][k].first);
                    res = max(res, dp[nxt][b][c][d][k]);
                }
            }
        }
        printf("%.2lf\n", res * 1.0 / 100);
    }
    return 0;
}