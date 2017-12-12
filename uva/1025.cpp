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
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7fffff7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 55, MAXT = 330;
int N, T, M1, M2;
int ts[MAXN];
bool fw[MAXN][MAXT], bw[MAXN][MAXT];
int dp[MAXN][MAXT];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int o = 1; cin >> N >> T; ++o)
    {
        memset(fw, 0, sizeof(fw));
        memset(bw, 0, sizeof(bw));
        memset(dp, 127, sizeof(dp));
        FO (i, N - 1)
            cin >> ts[i];
        cin >> M1;
        FO (i, M1)
        {
            int t;
            cin >> t;
            fw[0][t] = true;
            for (int j = 1; j < N - 1; ++j)
            {
                t += ts[j - 1];
                fw[j][t] = true;
            }
        }
        cin >> M2;
        FO (i, M2)
        {
            int t;
            cin >> t;
            bw[N - 1][t] = true;
            for (int j = N - 2; j > 0; --j)
            {
                t += ts[j];
                bw[j][t] = true;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i <= T; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (i > 0)
                    dp[j][i] = min(dp[j][i], dp[j][i - 1] + 1);
                if (fw[j][i])
                    dp[j + 1][i + ts[j]] = min(dp[j + 1][i + ts[j]], dp[j][i]);
                if (bw[j][i])
                    dp[j - 1][i + ts[j - 1]] = min(dp[j - 1][i + ts[j - 1]], dp[j][i]);
            }
        }
        if (dp[N - 1][T] > 100000)
            printf("Case Number %d: impossible\n", o);
        else
            printf("Case Number %d: %d\n", o, dp[N - 1][T]);
    }
    return 0;
}
