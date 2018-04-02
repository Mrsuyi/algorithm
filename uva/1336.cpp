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

const int MAXN = 1010;
int N, X;
double V;

struct Sec
{
    int pos, cost, inc;
    bool operator<(const Sec& rhs) const { return pos < rhs.pos; }
};

Sec secs[MAXN];
int sums[MAXN] = {0};
double dp[MAXN][MAXN][2];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N >> V >> X && N && V && X)
    {
        FO (i, N)
            cin >> secs[i].pos >> secs[i].cost >> secs[i].inc;
        sort(secs, secs + N);
        FO (i, N)
            sums[i] = (i ? sums[i - 1] : 0) + secs[i].inc;

        memset(dp, INF, sizeof(dp));
        Sec init = {X, 0, 0};
        int idx = lower_bound(secs, secs + N, init) - secs;
        if (idx > 0)
            dp[idx - 1][idx - 1][0] = dp[idx - 1][idx - 1][1] =
                secs[idx - 1].cost + (X - secs[idx - 1].pos) / V * sums[N - 1];
        if (idx < N)
            dp[idx][idx][0] = dp[idx][idx][1] =
                secs[idx].cost + (secs[idx].pos - X) / V * sums[N - 1];
        for (int i = 2; i <= N; ++i)
        {
            for (int l = 0, r = i - 1; r < N; ++l, ++r)
            {
                double sum = sums[N - 1] - sums[r] + sums[l];
                dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][0] + secs[l].cost +
                    (secs[l + 1].pos - secs[l].pos) / V * sum);
                dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][1] + secs[l].cost +
                    (secs[r].pos - secs[l].pos) / V * sum);

                sum = sums[N - 1] - sums[r - 1] + (l > 0 ? sums[l - 1] : 0);
                dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][0] + secs[r].cost +
                    (secs[r].pos - secs[l].pos) / V * sum);
                dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][1] + secs[r].cost +
                    (secs[r].pos - secs[r - 1].pos) / V * sum);
            }
        }

        printf("%d\n", int(min(dp[0][N - 1][0], dp[0][N - 1][1])));
    }
    return 0;
}