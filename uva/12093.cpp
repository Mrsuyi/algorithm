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

const int MAXN = 10100;
int N, C1, C2;
int in[MAXN];
vector<int> edges[MAXN];
int dp[MAXN][4];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N >> C1 >> C2 && N)
    {
        FO (i, N)
            edges[i].clear();
        FO (i, N - 1)
        {
            int u, v;
            cin >> u >> v;
            --u, --v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        queue<int> que;
        FO (i, N)
            if ((in[i] = edges[i].size()) <= 1)
                que.push(i);
        int res;
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            in[u] = 0;
            res = u;
            // -1
            dp[u][0] = 0;
            for (int v : edges[u])
                if (in[v] == 0)
                    dp[u][0] += dp[v][1];
            // 0
            dp[u][1] = 0;
            for (int v : edges[u])
                if (in[v] == 0)
                    dp[u][1] += dp[v][2];
            // 1
            int b = INT_MAX;
            for (int v : edges[u])
                if (in[v] == 0)
                    b = min(b, dp[u][0] - dp[v][1] + dp[v][3]);
            dp[u][2] = min(dp[u][0] + C1, b);
            // 2
            dp[u][3] = C2;
            for (int v : edges[u])
                if (in[v] == 0)
                    dp[u][3] += dp[v][0];

            dp[u][2] = min(dp[u][2], dp[u][3]);
            dp[u][1] = min(dp[u][1], dp[u][2]);
            dp[u][0] = min(dp[u][0], dp[u][1]);

            // expand
            for (int v : edges[u])
                if (in[v] && --in[v] <= 1)
                    que.push(v);
        }
        printf("%d\n", min(dp[res][1], min(dp[res][2], dp[res][3])));
    }
    return 0;
}