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

double L, D;
int N;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (~scanf("%lf %lf %d", &L, &D, &N))
    {
        vector<pdd> pts(N);
        FO (i, N)
        {
            double x, y;
            scanf("%lf %lf", &x, &y);
            double delta = sqrt(D * D - y * y);
            pts[i] = {x + delta, x - delta};
        }
        sort(pts.begin(), pts.end());
        int res = 1;
        double cur = pts[0].first;
        for (int i = 1; i < N;)
        {
            while (i < N && pts[i].second <= cur)
                ++i;
            if (i == N)
                break;
            ++res;
            cur = pts[i].first;
            ++i;
        }
        printf("%d\n", res);
    }
    return 0;
}