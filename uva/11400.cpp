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
struct Cate
{
    int vol, cov, lam, col;
    bool operator<(const Cate& rhs) const { return vol > rhs.vol; }
};
Cate cates[MAXN];
int dp[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    while (cin >> N && N)
    {
        FO (i, N)
            scanf("%d %d %d %d", &cates[i].vol, &cates[i].cov, &cates[i].col, &cates[i].lam);
        sort(cates, cates + N);
        memset(dp, 127, sizeof(dp));
        dp[0] = cates[0].cov + cates[0].col * cates[0].lam;
        for (int i = 1; i < N; ++i)
        {
            int mi = INT_MAX;
            for (int j = 0; j < i; ++j)
            {
                mi = min(mi, dp[j]);
                dp[j] += cates[j].col * cates[i].lam;
            }
            dp[i] = mi + cates[i].cov + cates[i].col * cates[i].lam;
        }
        printf("%d\n", *min_element(dp, dp + N));
    }
    return 0;
}
