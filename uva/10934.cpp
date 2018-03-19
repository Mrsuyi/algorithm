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

const int MAXK = 110, MAXM = 70;
llong dp[MAXK][MAXM] = {0};
llong K, N;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 1; i < MAXK; ++i)
    for (int j = 1; j < MAXM; ++j)
        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;

    while (cin >> K >> N && K)
    {
        llong* it = lower_bound(&dp[K][1], &dp[K][64], N);
        if (it == &dp[K][64])
            printf("More than 63 trials needed.\n");
        else
            printf("%d\n", it - &dp[K][0]);
    }
    return 0;
}