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
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 1010;
int N;
string s1, s2;
int S[MAXN] = {0}, T[MAXN] = {0};
int dp[MAXN][10][10];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> s1 >> s2)
    {
        N = s1.size();
        FO (i, N)
        {
            S[i + 1] = s1[i] - '0';
            T[i + 1] = s2[i] - '0';
        }
        memset(dp, INF, sizeof(dp));
        dp[0][S[1]][S[2]] = 0;
        for (int i = 1; i <= N; ++i)
        {
            for (int a = 0; a < 10; ++a)
            for (int b = 0; b < 10; ++b)
            {
                if (dp[i - 1][a][b] >= INF)
                    continue;
                int tim, dir;
                tim = abs(T[i] - a), dir = T[i] > a ? 1 : -1;
                for (int p = 0; p <= tim; ++p)
                    for (int q = 0; q <= p; ++q)
                    {
                        int na = (b + p * dir + 10) % 10;
                        int nb = (S[i + 2] + q * dir + 10) % 10;
                        dp[i][na][nb] = min(dp[i][na][nb], dp[i - 1][a][b] + tim);
                    }
                tim = 10 - abs(T[i] - a), dir = T[i] < a ? 1 : -1;
                for (int p = 0; p <= tim; ++p)
                    for (int q = 0; q <= p; ++q)
                    {
                        int na = (b + p * dir + 10) % 10;
                        int nb = (S[i + 2] + q * dir + 10) % 10;
                        dp[i][na][nb] = min(dp[i][na][nb], dp[i - 1][a][b] + tim);
                    }
            }
        }
        printf("%d\n", dp[N][0][0]);
    }
    return 0;
}