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
#define fi first
#define se second
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7;
double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 44;
int N, M;
double oris[MAXN], pts[MAXN];
double dp[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N >> M && N)
    {
        FO (i, N)
            cin >> oris[i];
        double res = 0;
        FO (o, N)
        {
            FO (i, N)
                pts[i] = fmod(oris[(i + o) % N] - oris[o] + 1.0, 1.0);
            FO (i, N)
            {
                dp[i][2] = 0.5 * sin((pts[i] - pts[0]) * 2 * PI);
                for (int j = 3; j <= M; ++j)
                    dp[i][j] = -100;
                for (int j = 0; j < i; ++j)
                {
                    double sec = 0.5 * sin((pts[i] - pts[j]) * 2 * PI);
                    for (int k = 2; k < M; ++k)
                        dp[i][k + 1] = max(dp[i][k + 1], sec + dp[j][k]);
                }
                double tot = dp[i][M] - dp[i][2];
                res = max(res, tot);
            }
        }
        printf("%.6lf\n", res);
    }
    return 0;
}