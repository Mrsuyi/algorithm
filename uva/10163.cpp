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

const int MAXN = 105, MAXM = 32, MAXP = 1010;
int N, M, U, ps[MAXM];
int dp1[MAXM][MAXN], dp2[MAXM][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N >> M && N)
    {
        FO (i, M)
            cin >> ps[i + 1];
        memset(dp1, 0, sizeof(dp1));
        dp1[0][0] = INF;
        for (int i = 1; i <= M; ++i)
        {
            for (int j = 0; j <= N; ++j)
            for (int k = 0; k <= j; ++k)
            {
                int cur = k ? ps[i] / k : INF;
                dp1[i][j] = max(dp1[i][j], min(dp1[i - 1][j - k], cur));
            }
        }
        U = dp1[M][N];
        memset(dp2, INF, sizeof(dp2));
        dp2[0][0] = 0;
        for (int i = 1; i <= M; ++i)
        {
            for (int j = 0; j <= N; ++j)
            for (int k = 0; k <= j && (!k || ps[i] / k >= U); ++k)
            {
                dp2[i][j] = min(dp2[i][j], dp2[i - 1][j - k] + (k ? ps[i] : 0));
            }
        }
        printf("%d %d\n", U, U ? dp2[M][N] : 0);
    }
    return 0;
}