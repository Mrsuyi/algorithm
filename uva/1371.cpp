#include <algorithm>
#include <array>
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
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 5050, MAXM = 55, INF = 0x3f3f3f3f;
int N, M;
char x[MAXN], y[MAXM];
int dp[MAXN][MAXM];

bool ok(int K)
{
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i)
        dp[i][0] = i;
    for (int i = 1; i <= M; ++i)
        dp[0][i] = i;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            dp[i][j] = dp[i - 1][j - 1] + (x[i] != y[j]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
        dp[i][0] = (dp[i][M] <= K) ? 0 : INF;
    }
    return dp[N][M] <= K;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    scanf("%d", &O);
    FO (o, O)
    {
        scanf("%s%s", y + 1, x + 1);
        N = strlen(x + 1), M = strlen(y + 1);
        int l = 0, r = M;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (ok(mid))
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", r);
    }
    return 0;
}