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
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;

inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 16;
int N, M, S, T;
bool vis[1 << MAXN][MAXN];
vector<int> edges[MAXN];

struct State
{
    int stt, robo;
    vector<pii> path;
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int C;
    cin >> C;
    FO (c, C)
    {
        cin >> N >> M >> S >> T;
        --S, --T;
        int init = 1 << S;
        FO (i, M)
        {
            int a;
            cin >> a;
            --a;
            init |= (1 << a);
        }
        FO (i, N)
            edges[i].clear();
        FO (i, N - 1)
        {
            int a, b;
            cin >> a >> b;
            --a, --b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        memset(vis, 0, sizeof(vis));
        queue<State> que;
        que.push({init, S, {}});
        while (!que.empty())
        {
            State cur = que.front();
            que.pop();
            for (int u = 0; u < N; ++u)
            {
                if (!(cur.stt & (1 << u)))
                    continue;
                for (int i = 0; i < edges[u].size(); ++i)
                {
                    int v = edges[u][i];
                    if (cur.stt & (1 << v))
                        continue;
                    int nstt = cur.stt;
                    nstt &= ~(1 << u);
                    nstt |= 1 << v;
                    int nrobo = (cur.robo == u) ? v : cur.robo;
                    if (vis[nstt][nrobo])
                        continue;
                    vis[nstt][nrobo] = true;
                    vector<pii> npath = cur.path;
                    npath.push_back({u + 1, v + 1});
                    if (nrobo == T)
                    {
                        printf("Case %d: %d\n", c + 1, npath.size());
                        for (int j = 0; j < npath.size(); ++j)
                            printf("%d %d\n", npath[j].first, npath[j].second);
                        printf("\n");
                        goto end;
                    }
                    que.push({nstt, nrobo, npath});
                }
            }
        }
        printf("Case %d: -1\n", c + 1);
        end:;
    }
    return 0;
}