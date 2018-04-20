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

const int MAXN = 5050, MAXK = 1018;
int N, K;
int dp[MAXN][MAXK], nums[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    scanf("%d", &O);
    FO (o, O)
    {
        scanf("%d %d", &K, &N);
        K += 8;
        FO (i, N)
            scanf("%d", &nums[N - i]);
        memset(dp, 0x0f, sizeof(dp));
        for (int i = 0; i <= N; ++i)
        {
            dp[i][0] = 0;
            for (int k = 1; k <= K; ++k)
                if (3 * k <= i)
                    dp[i][k] = min(dp[i - 1][k], dp[i - 2][k - 1] + (nums[i] - nums[i - 1]) * (nums[i] - nums[i - 1]));
        }
        printf("%d\n", dp[N][K]);
    }
    return 0;
}