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

const int MAXN = 23;
int N, K, tot;
bool conn[MAXN][MAXN];
bool vis[MAXN];
vector<int> path;

bool bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<int> que({1});
    vis[1] = true;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        if (cur == K)
            return true;
        for (int i = 1; i <= N; ++i)
        {
            if (conn[cur][i] && !vis[i])
            {
                vis[i] = true;
                que.push(i);
            }
        }
    }
    return false;
}

void dfs(int cur)
{
    if (cur == K)
    {
        ++tot;
        cout << 1;
        for (int i = 1; i < path.size(); ++i)
            cout << " " << path[i];
        cout << endl;
        return;
    }
    for (int i = 2; i <= N; ++i)
    {
        if (conn[cur][i] && !vis[i])
        {
            vis[i] = true;
            path.push_back(i);
            dfs(i);
            path.pop_back();
            vis[i] = false;
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    for (int t = 1; cin >> K; ++t)
    {
        printf("CASE %d:\n", t);
        int a, b;
        tot = 0;
        N = 1;
        memset(conn, 0, sizeof(conn));
        while (cin >> a >> b && a)
        {
            conn[a][b] = conn[b][a] = true;
            N = max(N, a);
            N = max(N, b);
        }
        if (bfs())
        {
            memset(vis, 0, sizeof(vis));
            path = {1};
            vis[1] = true;
            dfs(1);
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n", tot, K);
    }
    return 0;
}