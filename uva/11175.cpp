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

const int MAXN = 330;
int N, M, K;
bool conn[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    FO (n, N)
    {
        cin >> M >> K;
        memset(conn, 0, sizeof(conn));
        FO (k, K)
        {
            int u, v;
            cin >> u >> v;
            conn[u][v] = true;
        }
        bool res = true;
        for (int i = 0; i < M; ++i)
        for (int j = i + 1; j < M; ++j)
        {
            bool same = false, diff = false;
            for (int k = 0; k < M; ++k)
            {
                if (conn[i][k] && conn[j][k])
                    same = true;
                if (conn[i][k] ^ conn[j][k])
                    diff = true;
            }
            if (same && diff)
            {
                res = false;
                break;
            }
        }
        printf("Case #%d: %s\n", n + 1, res ? "Yes" : "No");
    }
    return 0;
}
