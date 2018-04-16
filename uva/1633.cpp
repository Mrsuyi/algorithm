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
double EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 410, MAXK = 11;
int T, N, K;
int dp[MAXN][1 << MAXK];
int to[1 << MAXK][2];

bool palin(int K, int num)
{
    for (int l = (1 << (K - 1)), r = 1; l > r; l >>= 1, r <<= 1)
        if (bool(num & l) ^ bool(num & r))
            return false;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;
    FO (o, T)
    {
        cin >> N >> K;
        if (K > N)
        {
            int res = 2;
            for (int i = 1; i < N; ++i)
                res = res * 2 % MOD;
            printf("%d\n", res);
            continue;
        }

        int ma = 1 << K;
        int mask = ma - 1;
        for (int i = 0; i < ma; ++i)
        {
            int i0 = i << 1, i1 = (i << 1) + 1;
            int a0 = i0 & mask, a1 = i1 & mask;
            to[i][0] = ((K + 1 <= N && palin(K + 1, i0)) || palin(K, a0)) ? -1 : a0;
            to[i][1] = ((K + 1 <= N && palin(K + 1, i1)) || palin(K, a1)) ? -1 : a1;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < ma; ++i)
            dp[K][i] = !palin(K, i);

        for (int i = K; i < N; ++i)
        {
            for (int j = 0; j < ma; ++j)
            {
                if (to[j][0] != -1)
                    dp[i + 1][to[j][0]] = (dp[i + 1][to[j][0]] + dp[i][j]) % MOD;
                if (to[j][1] != -1)
                    dp[i + 1][to[j][1]] = (dp[i + 1][to[j][1]] + dp[i][j]) % MOD;
            }
        }
        int res = 0;
        for (int i = 0; i < ma; ++i)
            res = (res + dp[N][i]) % MOD;
        printf("%d\n", res);
    }
    return 0;
}