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

const int MAXM = 105, MAXN = 8, MAXS = 15000;
double C;
int N, M, K;
char name[MAXN][10];
int si[MAXN], ki[MAXN];
double pi[MAXN][MAXM];
vector<vector<int>> stts;
map<vector<int>, int> mp;
int sel[MAXS][MAXN], buy[MAXS][MAXN];
int tot;
double dp[MAXM][MAXS];
int par[MAXM][MAXS], opt[MAXM][MAXS];
char res[MAXM][100];

void dfs(int i, vector<int>& stt, int sum)
{
    if (i == N)
    {
        mp[stt] = stts.size();
        stts.push_back(stt);
        return;
    }
    for (; sum <= K && stt[i] <= ki[i]; ++stt[i], ++sum)
        dfs(i + 1, stt, sum);
    stt[i] = 0;
}

void init()
{
    stts.clear();
    mp.clear();
    vector<int> stt(N, 0);
    dfs(0, stt, 0);
    tot = stts.size();
    for (int i = 0; i < tot; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            --stts[i][j];
            sel[i][j] = mp.count(stts[i]) ? mp[stts[i]] : -1;
            stts[i][j] += 2;
            buy[i][j] = mp.count(stts[i]) ? mp[stts[i]] : -1;
            --stts[i][j];
        }
    }
}

void update(int day, double val, int s1, int s2, int op)
{
    if (val > dp[day][s2])
    {
        dp[day][s2] = val;
        par[day][s2] = s1;
        opt[day][s2] = op;
    }
}

void work()
{
    FO (i, M + 1) FO (j, tot)
        dp[i][j] = -1;
    dp[0][0] = C;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < tot; ++j)
        {
            if (dp[i][j] < 0)
                continue;
            update(i + 1, dp[i][j], j, j, 0);
            for (int k = 0; k < N; ++k)
            {
                if (sel[j][k] != -1)
                    update(i + 1, dp[i][j] + pi[k][i] * si[k], j, sel[j][k], k + 1);
                if (buy[j][k] != -1)
                    update(i + 1, dp[i][j] - pi[k][i] * si[k], j, buy[j][k], -k - 1);
            }
        }
    }
}

void output()
{
    printf("%lf\n", dp[M][0]);
    int st = 0;
    for (int i = M; i > 0; --i)
    {
        int pa = par[i][st];
        int op = opt[i][st];
        if (op > 0)
            sprintf(res[i], "SELL %s", name[op - 1]);
        else if (op == 0)
            sprintf(res[i], "HOLD");
        else
            sprintf(res[i], "BUY %s", name[-op - 1]);
        st = pa;
    }
    for (int i = 1; i <= M; ++i)
        printf("%s\n", res[i]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (~scanf("%lf %d %d %d", &C, &M, &N, &K))
    {
        FO (i, N)
        {
            scanf("%s %d %d", name[i], &si[i], &ki[i]);
            FO (j, M)
                scanf("%lf", &pi[i][j]);
        }
        init();
        work();
        output();
    }
    return 0;
}