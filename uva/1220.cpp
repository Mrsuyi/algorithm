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

int N;
string boss;
unordered_map<string, vector<string>> children;
unordered_map<string, pair<pii, pii>> dp;

void dfs(const string& s)
{
    if (dp.count(s))
        return;
    for (const auto& child : children[s])
        dfs(child);
    dp[s] = {{1, 0}, {0, 0}};
    for (const auto& child : children[s])
    {
        dp[s].fi.fi += dp[child].se.fi;
        dp[s].fi.se |= dp[child].se.se;
        if (dp[child].fi.fi > dp[child].se.fi)
        {
            dp[s].se.fi += dp[child].fi.fi;
            dp[s].se.se |= dp[child].fi.se;
        }
        else if (dp[child].fi.fi < dp[child].se.fi)
        {
            dp[s].se.fi += dp[child].se.fi;
            dp[s].se.se |= dp[child].se.se;
        }
        else
        {
            dp[s].se.fi += dp[child].fi.fi;
            dp[s].se.se = 1;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N && N)
    {
        children.clear();
        dp.clear();
        cin >> boss;
        FO (i, N - 1)
        {
            string a, b;
            cin >> a >> b;
            children[b].push_back(a);
        }
        dfs(boss);
        if (dp[boss].fi.fi > dp[boss].se.fi)
            printf("%d %s\n", dp[boss].fi.fi, dp[boss].fi.se ? "No" : "Yes");
        else if (dp[boss].fi.fi < dp[boss].se.fi)
            printf("%d %s\n", dp[boss].se.fi, dp[boss].se.se ? "No" : "Yes");
        else
            printf("%d No\n", dp[boss].fi.fi);
    }
    return 0;
}
