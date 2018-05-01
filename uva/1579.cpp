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

const int MAXN = 510;
int N, nums[MAXN], dp[MAXN][MAXN], dp2[MAXN], mi[MAXN][MAXN], len[MAXN][MAXN];
bool st[MAXN], has[MAXN];

int get(int l , int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r)
    {
        mi[l][r] = nums[l];
        len[l][r] = 1;
        return dp[l][r] = 0;
    }
    // consecutive
    memset(has, 0, sizeof(has));
    int bgn = INT_MAX;
    for (int i = l; i <= r; ++i)
    {
        has[nums[i]] = true;
        bgn = min(bgn, nums[i]);
    }
    mi[l][r] = bgn;
    for (int i = bgn; has[i]; ++i)
        len[l][r] = i - bgn + 1;
    // combine
    dp[l][r] = INT_MAX;
    for (int k = l; k < r; ++k)
    {
        if (mi[l][k] < mi[k + 1][r])
            dp[l][r] = min(dp[l][r], get(l, k) + get(k + 1, r) + r - l + 1 - len[l][k]);
        else
            dp[l][r] = min(dp[l][r], get(l, k) + get(k + 1, r) + r - l + 1 - len[k + 1][r]);
    }
    return dp[l][r];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (~scanf("%d", &N))
    {
        FO (i, N)
            scanf("%d", &nums[i]);
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        dp2[0] = 0;
        FO (i, N)
        {
            int ma = -1;
            memset(st, 0, sizeof(st));
            for (int j = i; j >= 0; --j)
            {
                if (st[nums[j]])
                    break;
                st[nums[j]] = true;
                ma = max(ma, nums[j]);
                if (ma != i - j + 1 || dp2[j] == - 1)
                    continue;
                get(j, i);
                if (dp2[i + 1] == -1 || dp2[i + 1] > dp2[j] + dp[j][i])
                    dp2[i + 1] = dp2[j] + dp[j][i];
            }
        }
        if (dp2[N] == -1)
            printf("impossible\n");
        else
            printf("%d\n", dp2[N]);
    }
    return 0;
}