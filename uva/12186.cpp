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

const int MAXN = 100100;
int N, T;
int parent[MAXN], child[MAXN], que[MAXN];
vector<int> dp[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%d %d", &N, &T) && N)
    {
        memset(child, 0, sizeof(child));
        FO (i, N + 1)
            dp[i].clear();
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &parent[i]);
            ++child[parent[i]];
        }
        ++child[0];
        int l = 0, r = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (child[i] == 0)
                que[r++] = i;
        }
        while (l < r)
        {
            int cur = que[l++], val = 1;
            if (!dp[cur].empty())
            {
                sort(dp[cur].begin(), dp[cur].end());
                val = accumulate(dp[cur].begin(), dp[cur].begin() + ceil(dp[cur].size() * (T / 100.0)), 0);
            }
            dp[parent[cur]].push_back(val);
            if (--child[parent[cur]] == 0)
                que[r++] = parent[cur];
        }
        sort(dp[0].begin(), dp[0].end());
        int res = accumulate(dp[0].begin(), dp[0].begin() + ceil(dp[0].size() * (T / 100.0)), 0);
        printf("%d\n", res);
    }
    return 0;
}
