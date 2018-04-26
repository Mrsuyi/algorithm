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
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 40040, MAXM = 10010, MAXD = 10010;
int N, M, D;
int dp[MAXN][2], weis[MAXN], sums[MAXN] = {0};

bool ok(int K)
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= N / 2; ++i)
    {
        for (int j = i - 1; j >= 0 && i - j <= D; --j)
        {
            int l = 2 * j, m = i + j, r = 2 * i;
            if (sums[r] - sums[m] > K || sums[m] - sums[l] > K)
                continue;
            dp[i][0] = min(dp[i][0], dp[j][1] + 1);
            dp[i][1] = min(dp[i][1], dp[j][0] + 1);
        }
    }
    return dp[N / 2][(M - 1) & 1] <= M - 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    scanf("%d", &O);
    FO (o, O)
    {
        scanf("%d %d %d", &N, &M, &D);
        FO (i, N)
        {
            scanf("%d", &weis[i]);
            sums[i + 1] = sums[i] + weis[i];
        }
        if ((N & 1) || (2 * (M - 1) > N) || (2 * D * (M - 1) < N))
        {
            printf("BAD\n");
            continue;
        }
        int l = 0, r = INT_MAX;
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