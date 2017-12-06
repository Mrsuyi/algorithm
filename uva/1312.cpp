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

const int MAXN = 110;
int W, H, N;

struct Pt
{
    int x, y;
    bool operator<(const Pt& rhs)
    {
        return y < rhs.y;
    }
};
Pt pts[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        scanf("%d %d %d", &N, &W, &H);
        set<int> xs = {0, W};
        FO (i, N)
        {
            scanf("%d %d", &pts[i].x, &pts[i].y);
            xs.insert(pts[i].x);
        }
        sort(pts, pts + N);
        pts[N++] = {0, H};
        int res = INT_MIN, rx, ry;
        for (auto it1 = xs.begin(); it1 != xs.end(); ++it1)
        for (auto it2 = next(it1); it2 != xs.end(); ++it2)
        {
            int l = *it1, r = *it2, dx = r - l, y = 0;
            pts[N - 1].x = l + 1;
            for (int i = 0; i < N; ++i)
            {
                if (pts[i].x > l && pts[i].x < r)
                {
                    int len = min(dx, pts[i].y - y);
                    if (len > res)
                    {
                        res = len;
                        rx = l;
                        ry = y;
                    }
                    y = pts[i].y;
                }
            }
        }
        if (o)
            printf("\n");
        printf("%d %d %d\n", rx, ry, res);
    }
    return 0;
}
