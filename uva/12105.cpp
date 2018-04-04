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

const int MAXN = 110, MAXM = 3010;
int N, M;
int dp[MAXN][MAXM], pa[MAXN][MAXM];
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int o = 1; cin >> N >> M; ++o)
    {
        memset(dp, -1, sizeof(dp));
        memset(pa, -1, sizeof(pa));

        dp[0][0] = 0;
        for (int i = 0; i <= N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (j == 0)
                    dp[i][j] = 0;
                for (int k = 9; k >= 0; --k)
                {
                    int pi = i - cost[k];
                    if (pi < 0)
                        continue;
                    int pj = (10 * j + k) % M;
                    if (dp[pi][pj] != -1 && dp[i][j] < dp[pi][pj] + 1)
                    {
                        dp[i][j] = dp[pi][pj] + 1;
                        pa[i][j] = k;
                    }
                }
            }
        }

        string res;
        if (dp[N][0] <= 0)
            res = "-1";
        else
        {
            for (int i = N, j = 0, d = pa[i][j]; d != -1; d = pa[i][j])
            {
                res += '0' + d;
                i -= cost[d];
                j = (10 * j + d) % M;
            }
        }
        while (res.size() >= 2 && res[0] == '0' && res[1] == '0')
            res = res.substr(1);
        printf("Case %d: %s\n", o, res.data());
    }
    return 0;
}