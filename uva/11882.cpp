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
int R, C;
bool vis[MAXN][MAXN], vis2[MAXN][MAXN];
char mp[MAXN][MAXN];
string res, path;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pii que[MAXN * MAXN];

inline bool bigger(const string& a, const string& b)
{
    return a.size() > b.size() || (a.size() == b.size() && a > b);
}

string rest(int x, int y)
{
    memcpy(vis2, vis, sizeof(vis));
    int l = 0, r = 1;
    que[0] = {x, y};
    string res;
    while (l < r)
    {
        for (int i = 0; i < 4; ++i)
        {
            int p = que[l].first + dirs[i][0];
            int q = que[l].second + dirs[i][1];
            if (p < 0 || p >= R || q < 0 || q >= C || mp[p][q] == '#' || vis2[p][q])
                continue;
            vis2[p][q] = true;
            res.push_back(mp[p][q]);
            que[r++] = {p, q};
            ++r;
        }
        ++l;
    }
    return res;
}

void dfs(int x, int y)
{
    if (bigger(path, res))
        res = path;
    else
    {
        string rst = rest(x, y);
        if (path.size() + rst.size() < res.size())
            return;
        if (path.size() + rst.size() == res.size())
        {
            sort(rst.begin(), rst.end());
            reverse(rst.begin(), rst.end());
            rst = path + rst;
            if (bigger(res, rst))
                return;
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        int p = x + dirs[i][0];
        int q = y + dirs[i][1];
        if (p < 0 || p >= R || q < 0 || q >= C || mp[p][q] == '#' || vis[p][q])
            continue;
        vis[p][q] = true;
        path.push_back(mp[p][q]);
        dfs(p, q);
        vis[p][q] = false;
        path.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> R >> C && R)
    {
        FO (i, R)
            scanf("%s", mp[i]);
        res = "";
        FO (i, R) FO (j, C)
            if (mp[i][j] != '#')
            {
                path = string(1, mp[i][j]);
                memset(vis, 0, sizeof(vis));
                vis[i][j] = true;
                dfs(i, j);
            }
        cout << res << endl;
    }
    return 0;
}