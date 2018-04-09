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

const int MAXN = 10100;
int N;
int ps[MAXN], ts[MAXN], dp[MAXN][MAXN][2] = {0};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N)
    {
        FO (i, N)
            scanf("%d %d", &ps[i], &ts[i]);

        for (int l = N - 2; l >= 0; --l)
        {
            for (int r = l + 1; r < N; ++r)
            {
                dp[l][r][0] = min(dp[l + 1][r][0] + ps[l + 1] - ps[l], dp[l + 1][r][1] + ps[r] - ps[l]);
                if (dp[l][r][0] >= ts[l])
                    dp[l][r][0] = INF;
                dp[l][r][1] = min(dp[l][r - 1][0] + ps[r] - ps[l], dp[l][r - 1][1] + ps[r] - ps[r - 1]);
                if (dp[l][r][1] >= ts[r])
                    dp[l][r][1] = INF;
            }
        }
        int res = min(dp[0][N - 1][0], dp[0][N - 1][1]);
        if (res == INF)
            printf("No solution\n");
        else
            printf("%d\n", res);
    }
    return 0;
}