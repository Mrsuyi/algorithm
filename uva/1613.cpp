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
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7fffff7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 10010;
int N, M, K;
vector<int> edges[MAXN];
bool has[MAXN][MAXN];
int que[MAXN], res[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N >> M)
    {
        K = 0;
        memset(has, 0, sizeof(has));
        memset(res, 0, sizeof(res));
        for (int i = 1; i <= N; ++i)
            edges[i].clear();
        for (int i = 0; i < M; ++i)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for (int i = 1; i <= N; ++i)
            K = max(K, (int)edges[i].size());
        K += !(K & 1);
        int l = 0, r = 1;
        que[0] = 1;
        while (l < r)
        {
            int u = que[l++];
            for (int j = 1; j <= K; ++j)
            {
                if (!has[u][j])
                {
                    res[u] = j;
                    break;
                }
            }
            for (int i = 0; i < edges[u].size(); ++i)
            {
                int v = edges[u][i];
                if (res[v] > 0)
                    continue;
                has[v][res[u]] = true;
                if (res[v] == -1)
                    continue;
                res[v] = -1;
                que[r++] = v;
            }
        }
        cout << K << endl;
        for (int i = 1; i <= N; ++i)
            cout << res[i] << endl;
        cout << endl;
    }
    return 0;
}