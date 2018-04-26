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

const int MAXN = 220;
int N, L, R;
pii ls[MAXN], rs[MAXN];
int dp[MAXN][MAXN][2];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    scanf("%d", &O);
    FO (o, O)
    {
        scanf("%d", &N);
        L = R = 0;
        FO (i, N)
        {
            char s[10];
            scanf("%s", s);
            if (s[0] == 'A')
            {
                scanf("%d %d", &ls[L].first, &ls[L].second);
                ++L;
            }
            else
            {
                scanf("%d %d", &rs[R].first, &rs[R].second);
                ++R;
            }
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0][0] = dp[0][0][1] = 0;
        FO (l, L + 1) FO (r, R + 1)
        {
            int bgn, end;
            bgn = dp[l][r][1] - 10, end = bgn;
            for(int k = l; k < L; ++k)
            {
                bgn = max(bgn + 10, ls[k].first);
                end = max(bgn + ls[k].second, end + 10);
                dp[k + 1][r][0] = min(dp[k + 1][r][0], end);
            }
            bgn = dp[l][r][0] - 10, end = bgn;
            for (int k = r; k < R; ++k)
            {
                bgn = max(bgn + 10, rs[k].first);
                end = max(bgn + rs[k].second, end + 10);
                dp[l][k + 1][1] = min(dp[l][k + 1][1], end);
            }
        }
        printf("%d\n", min(dp[L][R][0], dp[L][R][1]));
    }
    return 0;
}