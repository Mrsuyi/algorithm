#include <algorithm>
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

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 1010;
int N;
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
struct Pt
{
    double x, y, r;
    Pt(double x, double y, double r) : x(x), y(y), r(r) {}
    Pt() : Pt(0, 0, 0) {}
    bool cross(const Pt& other)
    {
        return dist(x, y, other.x, other.y) <= (r + other.r);
    }
    bool cross_hor(const double yy)
    {
        return fabs(yy - y) <= r;
    }
    bool cross_ver(const double xx)
    {
        return fabs(xx - x) <= r;
    }
    double south(const double xx)
    {
        return y - sqrt(r * r - pow(fabs(x - xx), 2));
    }
};
Pt pt[MAXN];
bool vis[MAXN];
vector<int> top;
double resl, resr;

bool dfs(int cur)
{
    vis[cur] = true;
    if (pt[cur].cross_hor(0))
        return true;
    if (pt[cur].cross_ver(0))
        resl = min(resl, pt[cur].south(0));
    if (pt[cur].cross_ver(1000))
        resr = min(resr, pt[cur].south(1000));
    for (int i = 0; i < N; ++i)
    {
        if (vis[i] || i == cur)
            continue;
        if (pt[cur].cross(pt[i]) && dfs(i))
            return true;
    }
    return false;
}

int main()
{
    while (cin >> N)
    {
        top.clear();
        memset(vis, 0, sizeof(vis));
        resl = 1000, resr = 1000;
        FO (i, N)
        {
            cin >> pt[i].x >> pt[i].y >> pt[i].r;
            if (pt[i].cross_hor(1000))
                top.push_back(i);
        }
        bool can = false;
        for (int i = 0; i < top.size(); ++i)
        {
            if (dfs(top[i]))
            {
                can = true;
                break;
            }
        }
        if (can)
            printf("IMPOSSIBLE\n");
        else
            printf("%.2lf %.2lf %.2lf %.2lf\n", 0.0, resl, 1000.0, resr);
    }
    return 0;
}