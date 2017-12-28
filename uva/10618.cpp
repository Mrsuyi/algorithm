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
const int INF = 0x7f7f7f7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 77;
int N;
char seq[MAXN];

int cost[4][4][3][2][4];
int dp[MAXN][4][4][3];
vector<int> par[MAXN][4][4][3];
int c2t[128];
char p2c[3] = {'L', 'R', '.'};

void init()
{
    c2t['U'] = 0;
    c2t['R'] = 1;
    c2t['D'] = 2;
    c2t['L'] = 3;
    memset(cost, -1, sizeof(cost));
    FO (l, 4) FO (r, 4) FO (pre, 3) FO (cur, 2) FO (to, 4)
    {
        if ((l == 1 && (r == 0 || r == 2) && cur == 1 && to != r) || // cross
            (r == 3 && (l == 0 || l == 2) && cur == 0 && to != l) ||
            (cur == 0 && to == r) || // dup
            (cur == 1 && to == l))
            continue;
        if (pre != cur)
            cost[l][r][pre][cur][to] = 1;
        else
        {
            int lst = cur ? r : l;
            if (to == lst)
                cost[l][r][pre][cur][to] = 3;
            else if ((to ^ lst) & 1)
                cost[l][r][pre][cur][to] = 5;
            else
                cost[l][r][pre][cur][to] = 7;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    init();
    while (scanf("%s", seq) && seq[0] != '#')
    {
        N = strlen(seq);
        memset(dp, INF, sizeof(dp));
        dp[0][3][1][2] = 0;
        for (int i = 0; i < N; ++i)
        {
            vector<int> tos(1, c2t[seq[i]]);
            if (seq[i] == '.')
            {
                tos = {0, 1, 2, 3};
                FO (l, 4) FO (r, 4) FO (pre, 3)
                    if (dp[i][l][r][pre] < dp[i + 1][l][r][2])
                    {
                        dp[i + 1][l][r][2] = dp[i][l][r][pre];
                        par[i + 1][l][r][2] = {l, r, pre};
                    }
            }
            FO (l, 4) FO (r, 4) FO (pre, 3)
            {
                if (dp[i][l][r][pre] == INF)
                    continue;
                for (int to : tos)
                {
                    if (cost[l][r][pre][0][to] != -1 && dp[i][l][r][pre] + cost[l][r][pre][0][to] < dp[i + 1][to][r][0])
                    {
                        dp[i + 1][to][r][0] = dp[i][l][r][pre] + cost[l][r][pre][0][to];
                        par[i + 1][to][r][0] = {l, r, pre};
                    }
                    if (cost[l][r][pre][1][to] != -1 && dp[i][l][r][pre] + cost[l][r][pre][1][to] < dp[i + 1][l][to][1])
                    {
                        dp[i + 1][l][to][1] = dp[i][l][r][pre] + cost[l][r][pre][1][to];
                        par[i + 1][l][to][1] = {l, r, pre};
                    }
                }
            }
        }
        vector<int> stt;
        int mi = INT_MAX;
        FO (l, 4) FO (r, 4) FO (pre, 3)
            if (dp[N][l][r][pre] != INF && dp[N][l][r][pre] < mi)
            {
                mi = dp[N][l][r][pre];
                stt = {l, r, pre};
            }
        string res;
        for (int i = N; i > 0; --i)
        {
            res.push_back(p2c[stt[2]]);
            stt = par[i][stt[0]][stt[1]][stt[2]];
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}