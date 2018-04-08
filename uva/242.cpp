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

const int MAXV = 1111;
int S, N;
int dp[MAXV];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> S && S)
    {
        cin >> N;
        vector<vector<int>> combs(N);
        FO (i, N)
        {
            int L;
            cin >> L;
            combs[i].resize(L + 1);
            combs[i][0] = L;
            for (int j = 1; j <= L; ++j)
                cin >> combs[i][j];
            sort(combs[i].begin() + 1, combs[i].end(), greater<int>());
        }
        sort(combs.begin(), combs.end());
        int ma = 0, res = 0;
        FO (i, N)
        {
            memset(dp, INF, sizeof(dp));
            dp[0] = 0;
            for (int j = 1; j < MAXV; ++j)
            {
                for (int k = 1; k < combs[i].size(); ++k)
                {
                    if (j - combs[i][k] >= 0)
                        dp[j] = min(dp[j], dp[j - combs[i][k]] + 1);
                }
                if (dp[j] > S)
                {
                    if (j > ma)
                    {
                        ma = j;
                        res = i;
                    }
                    break;
                }
            }
        }
        printf("max coverage =%4d :", ma - 1);
        for (int i = combs[res].size() - 1; i > 0; --i)
            printf("%3d", combs[res][i]);
        printf("\n");
    }
    return 0;
}