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

const int MAXN = 55;
int N, L;
int pos[MAXN], dp[MAXN][MAXN], cut[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    memset(dp, 0, sizeof(dp));
    FO (i, MAXN - 1)
        cut[i][i + 1] = i + 1;
    while (cin >> L && L)
    {
        cin >> N;
        pos[0] = 0;
        for (int i = 1; i <= N; ++i)
            scanf("%d", &pos[i]);
        N += 2;
        pos[N - 1] = L;
        for (int l = 3; l <= N; ++l)
        {
            for (int i = 0, j = l - 1; j < N; ++i, ++j)
            {
                dp[i][j] = INF;
                for (int k = cut[i][j - 1]; k <= cut[i + 1][j]; ++k)
                {
                    if (dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        cut[i][j] = k;
                    }
                }
                dp[i][j] += pos[j] - pos[i];
            }
        }
        printf("The minimum cutting is %d.\n", dp[0][N - 1]);
    }
    return 0;
}
