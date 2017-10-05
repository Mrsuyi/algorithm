#include <algorithm>
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

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

const int MAXN = 100100;
int N, M;
int d[MAXN];
bool vis[MAXN];
int que[MAXN * 8];
vector<pii> edge[MAXN];
vector<int> res;

void bfs1()
{
    memset(d, 0, sizeof(int) * (N + 10));
    que[0] = N;
    for (int l = 0, r = 1; l < r; ++l)
    {
        int u = que[l];
        FO (i, edge[u].size())
        {
            int v = edge[u][i].fi;
            if (d[v] != 0 || v == N)
                continue;
            d[v] = d[u] + 1;
            que[r++] = v;
        }
    }
}

void bfs2()
{
    memset(vis, 0, sizeof(bool) * (N + 10));
    res.clear();
    vector<int> cur(1, 1);
    for (; d[cur[0]] != 0;)
    {
        int minw = INT_MAX;
        FO (i, cur.size())
        {
            int u = cur[i];
            FO (j, edge[u].size())
            {
                int v = edge[u][j].fi;
                int w = edge[u][j].se;
                if (d[v] != d[u] - 1)
                    continue;
                minw = min(minw, w);
            }
        }
        res.push_back(minw);
        vector<int> nxt;
        FO (i, cur.size())
        {
            int u = cur[i];
            FO (j, edge[u].size())
            {
                int v = edge[u][j].fi;
                int w = edge[u][j].se;
                if (d[v] != d[u] - 1 || vis[v] || w != minw)
                    continue;
                nxt.push_back(v);
                vis[v] = true;
            }
        }
        swap(nxt, cur);
    }
}

int main()
{
    while (cin >> N >> M)
    {
        FO (i, N + 1)
            edge[i].clear();
        FO (i, M)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (a == b)
                continue;
            edge[a].push_back(pii(b, c));
            edge[b].push_back(pii(a, c));
        }
        bfs1();
        cout << d[1] << endl;
        bfs2();
        cout << res[0];
        FOR (i, 1, res.size())
            cout << " " << res[i];
        cout << endl;
    }
    return 0;
}