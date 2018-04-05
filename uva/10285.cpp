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

const int MAXM = 110;
int R, C;
int mp[MAXM][MAXM];
int dp[MAXM][MAXM];
string name;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int r, int c)
{
    if (dp[r][c] != -1)
        return dp[r][c];
    dp[r][c] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int p = r + dirs[i][0];
        int q = c + dirs[i][1];
        if (p >= 0 && p < R && q >= 0 && q < C && mp[p][q] < mp[r][c])
            dp[r][c] = max(dp[r][c], dfs(p, q) + 1);
    }
    return dp[r][c];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;
    FO (o, N)
    {
        cin >> name >> R >> C;
        FO (i, R) FO (j, C)
            cin >> mp[i][j];
        memset(dp, -1, sizeof(dp));
        int res = 0;
        FO (i, R) FO (j, C)
            res = max(res, dfs(i, j));
        cout << name << ": " << res << endl;
    }
    return 0;
}