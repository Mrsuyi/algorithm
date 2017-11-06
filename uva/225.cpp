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

const int OFFSET = 250;
int N, M, tot;
map<int, set<int>> xs, ys;
char d2c[4] = {'e', 'n', 's', 'w'};
int dirs[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int d2d[5][4] = {{1, 2}, {0, 3}, {0, 3}, {1, 2}, {0, 1, 2, 3}};
bool vis[OFFSET * 2][OFFSET * 2];
string path;

void dfs(int x, int y, int cur, int dir)
{
    if (cur > N)
    {
        if (x == 0 && y == 0)
        {
            ++tot;
            cout << path << endl;
        }
        return;
    }
    for (int i = 0; i < ((dir == 4) ? 4 : 2); ++i)
    {
        int nxtdir = d2d[dir][i];
        int p = x + dirs[nxtdir][0] * cur;
        int q = y + dirs[nxtdir][1] * cur;
        int pp = p + OFFSET;
        int qq = q + OFFSET;
        if (vis[pp][qq])
            continue;
        if (abs(p) + abs(q) > (cur + 1 + N) * (N - cur) / 2)
            continue;
        if (nxtdir == 1 || nxtdir == 2)
        {
            auto it = xs[x].lower_bound(min(y, q));
            if (it != xs[x].end() && *it <= max(y, q))
                continue;
        }
        else
        {
            auto it = ys[y].lower_bound(min(x, p));
            if (it != ys[y].end() && *it <= max(x, p))
                continue;
        }
        vis[pp][qq] = true;
        path.push_back(d2c[nxtdir]);
        dfs(p, q, cur + 1, nxtdir);
        path.pop_back();
        vis[pp][qq] = false;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        tot = 0;
        xs.clear();
        ys.clear();
        path.clear();
        memset(vis, 0, sizeof(vis));
        cin >> N >> M;
        FO (m, M)
        {
            int x, y;
            cin >> x >> y;
            xs[x].insert(y);
            ys[y].insert(x);
        }
        vis[0][0] = true;
        dfs(0, 0, 1, 4);
        printf("Found %d golygon(s).\n\n", tot);
    }
    return 0;
}