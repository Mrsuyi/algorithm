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

const int MAXN = 5050;
int N, M;
string s1, s2;
int bgn1[127], end1[127], bgn2[127], end2[127];
int dp[MAXN][MAXN], cnt[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        cin >> s1 >> s2;
        N = s1.size();
        M = s2.size();
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        memset(bgn1, INF, sizeof(bgn1));
        memset(end1, -1, sizeof(end1));
        memset(bgn2, INF, sizeof(bgn2));
        memset(end2, -1, sizeof(end2));
        for (int i = 1; i <= N; ++i)
        {
            if (bgn1[s1[i]] == INF) bgn1[s1[i]] = i;
            end1[s1[i]] = i;
        }
        for (int i = 1; i <= M; ++i)
        {
            if (bgn2[s2[i]] == INF) bgn2[s2[i]] = i;
            end2[s2[i]] = i;
        }
        cnt[0][0] = 0;
        dp[0][0] = 0;
        for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= M; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int a = (i > 0) ? (dp[i - 1][j] + cnt[i - 1][j]) : INT_MAX;
            int b = (j > 0) ? (dp[i][j - 1] + cnt[i][j - 1]) : INT_MAX;
            dp[i][j] = min(a, b);
            if (i > 0)
            {
                cnt[i][j] = cnt[i - 1][j];
                if (bgn1[s1[i]] == i && bgn2[s1[i]] > j)
                    ++cnt[i][j];
                if (end1[s1[i]] == i && end2[s1[i]] <= j)
                    --cnt[i][j];
            }
            else if (j > 0)
            {
                cnt[i][j] = cnt[i][j - 1];
                if (bgn2[s2[j]] == j && bgn1[s2[j]] > i)
                    ++cnt[i][j];
                if (end2[s2[j]] == j && end1[s2[j]] <= i)
                    --cnt[i][j];
            }
        }
        printf("%d\n", dp[N][M]);
    }
    return 0;
}
