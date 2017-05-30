#include <climits>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
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

struct Build
{
    int id;
    double x, y, w, d, h;

    bool operator<(const Build& other)
    {
        return x < other.x || (x == other.x && y < other.y);
    }
} builds[110];

double xs[220];

bool visible(int i)
{
    FO (j, M - 1)
    {
        double l = xs[j];
        double r = xs[j + 1];
        if (builds[i].x >= r || builds[i].x + builds[i].w <= l)
            continue;
        FO (k, N)
        {
            if (k != i &&
                builds[k].x <= l &&
                builds[k].x + builds[k].w >= r &&
                builds[k].y < builds[i].y &&
                builds[k].h >= builds[i].h)
                goto next;
        }
        return true;
        next:;
    }
    return false;
}

int main()
{
    int t = 0;
    while (cin >> N)
    {
        ++t;
        if (N == 0)
            break;
        FO (i, N)
        {
            cin >> builds[i].x >> builds[i].y >> builds[i].w >> builds[i].d >> builds[i].h;
            builds[i].id = i + 1;
            xs[2 * i] = builds[i].x;
            xs[2 * i + 1] = builds[i].x + builds[i].w;
        }
        sort(builds, builds + N);
        sort(xs, xs + 2 * N);
        M = unique(xs, xs + 2 * N) - xs;
        if (t > 1)
            printf("\n");
        printf("For map #%d, the visible buildings are numbered as follows:\n", t);
        bool fir = true;
        FO (i, N)
        {
            if (visible(i))
            {
                if (fir)
                    fir = false;
                else
                    printf(" ");
                printf("%d", builds[i].id);
            }
        }
        printf("\n");
    }
    return 0;
}