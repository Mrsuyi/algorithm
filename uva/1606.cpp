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

const int MAXN = 1010;
int N, res, ctrx, ctry;
int ori[MAXN][3];

struct Pt
{
    int x, y;
    double rad;
    bool operator<(const Pt& rhs) const
    {
        return rad < rhs.rad;
    }
};
Pt pts[MAXN];

bool acute(const Pt& a, const Pt& b)
{
    return a.x * b.y - a.y * b.x >= 0;
}

void solve(int ctr)
{
    int j = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i == ctr)
            continue;
        pts[j].x = ori[i][0] - ori[ctr][0];
        pts[j].y = ori[i][1] - ori[ctr][1];
        if (ori[i][2])
        {
            pts[j].x = -pts[j].x;
            pts[j].y = -pts[j].y;
        }
        pts[j].rad = atan2(pts[j].y, pts[j].x);
        ++j;
    }
    sort(pts, pts + N - 1);
    int cnt = 1;
    for (int i = 0, j = 0; i < N - 1; ++i, --cnt)
    {
        if (j == i)
        {
            j = (j + 1) % (N - 1);
            ++cnt;
        }
        while (j != i && acute(pts[i], pts[j]))
        {
            j = (j + 1) % (N - 1);
            ++cnt;
        }
        res = max(res, cnt);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N && N)
    {
        FO (i, N)
            scanf("%d %d %d", &ori[i][0], &ori[i][1], &ori[i][2]);
        res = 1;
        FO (i, N)
            solve(i);
        printf("%d\n", res);
    }
    return 0;
}