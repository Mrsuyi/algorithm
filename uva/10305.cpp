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

int N, M;
int res[110];
int pt;
int edge[110][110];
int vis[110];

void dfs(int cur)
{
    vis[cur] = true;
    FOR (i, 1, N + 1)
        if (edge[cur][i] && !vis[i])
            dfs(i);
    res[pt--] = cur;
}

int main()
{
    while (cin >> N >> M)
    {
        if (M == 0 && N == 0)
            break;
        pt = N;
        memset(edge, 0, sizeof(edge));
        memset(vis, 0, sizeof(vis));
        FO (i, M)
        {
            int a, b;
            cin >> a >> b;
            edge[a][b] = 1;
        }
        FOR (i, 1, N + 1)
            if (!vis[i])
                dfs(i);
        cout << res[1];
        FOR (i, 2, N + 1)
            cout << " " << res[i];
        cout << endl;
    }
    return 0;
}