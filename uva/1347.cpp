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
const int INF = 0x7fffff7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    while (cin >> N)
    {
        vector<pii> pts(N);
        FO (i, N)
            cin >> pts[i].fi >> pts[i].se;
        if (N == 1)
        {
            printf("0.00\n");
            continue;
        }
        vector<vector<double>> dist(N + 1, vector<double>(N + 1, 0));
        FO (i, N) FO (j, N)
            dist[i][j] = sqrt((pts[i].fi - pts[j].fi) * (pts[i].fi - pts[j].fi) + (pts[i].se - pts[j].se) * (pts[i].se - pts[j].se));
        vector<vector<double>> dp(N + 1, vector<double>(N + 1, DBL_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < N; ++i)
        for (int j = i; j < N; ++j)
        {
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dist[j][j + 1]);
            dp[j][j + 1] = min(dp[j][j + 1], dp[i][j] + dist[i][j + 1]);
            dp[j][j] = min(dp[j][j], dp[i][j] + dist[i][j]);
        }
        printf("%.2lf\n", dp[N - 1][N - 1]);
    }
    return 0;
}
