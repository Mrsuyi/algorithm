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

const int MAXN = 110;
int N, M;
int mt[MAXN][MAXN], dp[MAXN][MAXN], nxt[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> M >> N)
    {
        FO (i, M) FO (j, N)
            cin >> mt[i][j];
        memset(dp, 127, sizeof(dp));
        RFO (i, N) FO (j, M)
        {
            if (i == N - 1)
            {
                dp[j][i] = mt[j][i];
                continue;
            }
            int xs[3];
            xs[0] = (j - 1 + M) % M;
            xs[1] = j;
            xs[2] = (j + 1) % M;
            sort(xs, xs + 3);
            for (int k = 0; k < 3; ++k)
            {
                if (mt[j][i] + dp[xs[k]][i + 1] < dp[j][i])
                {
                    dp[j][i] = mt[j][i] + dp[xs[k]][i + 1];
                    nxt[j][i] = xs[k];
                }
            }
        }
        int res = 0;
        for (int i = 1; i < M; ++i)
            if (dp[i][0] < dp[res][0])
                res = i;
        for (int i = 0, j = res; i < N; ++i)
        {
            if (i) printf(" ");
            printf("%d", j + 1);
            j = nxt[j][i];
        }
        printf("\n%d\n", dp[res][0]);
    }
    return 0;
}
