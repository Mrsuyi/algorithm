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
const int INF = 0x0fffffff, MOD = 1e9 + 7, EPS = 1e-8;

inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 100100;
int N;
int gas[MAXN * 2], cost[MAXN * 2];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        cin >> N;
        FO (i, N)
            cin >> gas[i];
        FO (i, N)
            cin >> cost[i];
        int pre = 0, tank = 0, bgn = 0;
        FO (i, N)
        {
            if (tank + gas[i] >= cost[i])
                tank += gas[i] - cost[i];
            else
            {
                pre += cost[i] - (tank + gas[i]);
                bgn = i + 1;
                tank = 0;
            }
        }
        if (tank >= pre)
            printf("Case %d: Possible from station %d\n", t + 1, bgn + 1);
        else
            printf("Case %d: Not possible\n", t + 1);
    }
    return 0;
}