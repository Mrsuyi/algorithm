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

int N;
int edge[60][60];
int vis[60];

bool dfs(int cur)
{
    vis[cur] = -1;
    FO (i, 52)
    {
        if (!edge[cur][i])
            continue;
        int nxt = (i + 26) % 52;
        if (vis[nxt] == -1)
            return true;
        if (vis[nxt] == 0 && dfs(nxt))
            return true;
    }
    vis[cur] = 1;
    return false;
}

int main()
{
    while (cin >> N)
    {
        memset(edge, 0, sizeof(edge));
        memset(vis, 0, sizeof(vis));
        FO (n, N)
        {
            string s;
            cin >> s;
            int vs[4] = {-1, -1, -1, -1};
            FO (i, 4)
            {
                if (s[2 * i] == '0')
                    continue;
                vs[i] = (s[2 * i] - 'A') + ((s[2 * i + 1] == '+') ? 26 : 0);
            }
            for (int i = 0; i < 4; ++i)
            for (int j = i + 1; j < 4; ++j)
            {
                if (vs[i] == -1 || vs[j] == -1)
                    continue;
                edge[vs[i]][vs[j]] = edge[vs[j]][vs[i]] = 1;
            }
        }
        bool res = false;
        FO (i, 52)
            if (!vis[i])
                res |= dfs(i);
        cout << (res ? "unbounded" : "bounded") << endl;
    }
    return 0;
}