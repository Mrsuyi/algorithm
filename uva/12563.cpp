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

const int MAXN = 52, MAXT = MAXN * 3 * 60;
int N, T;
pii dp[MAXT];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        cin >> N >> T;
        T = min(T, MAXT);
        memset(dp, 0, sizeof(dp));
        FO (i, N)
        {
            int t;
            cin >> t;
            for (int j = T - 1; j >= t; --j)
            {
                pii tmp = {dp[j - t].fi + 1, dp[j - t].se + t};
                if (tmp.se < T && tmp > dp[j])
                    dp[j] = tmp;
            }
        }
        printf("Case %d: %d %d\n", o + 1, dp[T - 1].fi + 1, dp[T - 1].se + 678);
    }
    return 0;
}
