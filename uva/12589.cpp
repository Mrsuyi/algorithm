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
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 55, MAXH = 2550;
int N, K;
pii vecs[MAXN];
int dp[MAXH][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        cin >> N >> K;
        FO (i, N)
            cin >> vecs[i].first >> vecs[i].second;
        sort(vecs, vecs + N, [](const pii& lhs, const pii& rhs){
            return lhs.second * rhs.first > lhs.first * rhs.second;
        });
        memset(dp, 0xc0, sizeof(dp));
        dp[0][0] = 0;
        FO (i, N)
        {
            int x = vecs[i].first, y = vecs[i].second;
            for (int h = MAXH - 1; h >= y; --h)
                for (int k = K; k > 0; --k)
                    dp[h][k] = max(dp[h][k], dp[h - y][k - 1] + 2 * x * (h - y) + x * y);
        }
        int res = 0;
        FO (h, MAXH)
            res = max(res, dp[h][K]);
        printf("Case %d: %d\n", o + 1, res);
    }
    return 0;
}