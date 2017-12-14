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

const int MAXN = 1010;
int N;
char s[MAXN];
bool palin[MAXN][MAXN];
int dp[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int O;
    cin >> O;
    FO (o, O)
    {
        scanf("%s", s);
        N = strlen(s);
        for (int i = 0; i < N; ++i)
        for (int j = i; j >= 0; --j)
            palin[j][i] = (s[j] == s[i]) && (i - j < 3 || palin[j + 1][i - 1]);
        memset(dp, 127, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < N; ++i)
        for (int j = i; j >= 0; --j)
        {
            if (palin[j][i])
                dp[i + 1] = min(dp[i + 1], dp[j] + 1);
        }
        printf("%d\n", dp[N]);
    }
    return 0;
}
