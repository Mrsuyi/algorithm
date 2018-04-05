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
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 45, MAXM = 22;
int N;
int color[MAXN][4];
int dp[MAXN][MAXN][MAXN][MAXN];

int cnt1(int num)
{
    int res = 0;
    while (num)
    {
        ++res;
        num &= num - 1;
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N && N)
    {
        FO (i, N) FO (j, 4)
            cin >> color[i][j];
        memset(dp, INF, sizeof(dp));
        int res = 0;
        dp[0][0][0][0] = 0;
        for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= N; ++j)
        for (int k = 0; k <= N; ++k)
        for (int l = 0; l <= N; ++l)
        {
            int cur = dp[i][j][k][l];
            int cnt = cnt1(cur);
            if (cnt > 5)
                continue;
            res = max(res, ((i + j + k + l) - cnt) / 2);
            if (cnt == 5)
                continue;
            if (i < N)
            {
                if (cur & (1 << color[i][0]))
                    dp[i + 1][j][k][l] = cur ^ (1 << color[i][0]);
                else
                    dp[i + 1][j][k][l] = cur | (1 << color[i][0]);
            }
            if (j < N)
            {
                if (cur & (1 << color[j][1]))
                    dp[i][j + 1][k][l] = cur ^ (1 << color[j][1]);
                else
                    dp[i][j + 1][k][l] = cur | (1 << color[j][1]);
            }
            if (k < N)
            {
                if (cur & (1 << color[k][2]))
                    dp[i][j][k + 1][l] = cur ^ (1 << color[k][2]);
                else
                    dp[i][j][k + 1][l] = cur | (1 << color[k][2]);
            }
            if (l < N)
            {
                if (cur & (1 << color[l][3]))
                    dp[i][j][k][l + 1] = cur ^ (1 << color[l][3]);
                else
                    dp[i][j][k][l + 1] = cur | (1 << color[l][3]);
            }
        }
        cout << res << endl;
    }
    return 0;
}