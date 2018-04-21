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
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 110;
llong N, D, M;
llong hs[MAXN];
llong dp[MAXN][2 * MAXN * MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    llong O;
    cin >> O;
    FO (o, O)
    {
        cin >> N >> D;
        FO (i, N)
            cin >> hs[i];
        set<llong> st;
        for (llong i = 0; i < N; ++i)
            for (llong j = -(N - 1); j < N; ++j)
                st.insert(hs[i] + D * j);
        vector<llong> cans(st.begin(), st.end());
        M = cans.size();
        memset(dp, -1, sizeof(dp));
        llong i0 = lower_bound(cans.begin(), cans.end(), hs[0]) - cans.begin();
        dp[0][i0] = 0;
        for (llong i = 1; i < N; ++i)
        {
            deque<llong> que;
            for (llong j = 0, k = 0; j < M; ++j)
            {
                while (!que.empty() && cans[que.front()] < cans[j] - D)
                    que.pop_front();
                for (; k < M && cans[k] <= cans[j] + D; ++k)
                {
                    if (dp[i - 1][k] == -1)
                        continue;
                    while (!que.empty() && dp[i - 1][que.back()] >= dp[i - 1][k])
                        que.pop_back();
                    que.push_back(k);
                }
                if (!que.empty())
                    dp[i][j] = dp[i - 1][que.front()] + abs(hs[i] - cans[j]);
            }
        }
        llong in = lower_bound(cans.begin(), cans.end(), hs[N - 1]) - cans.begin();
        if (dp[N - 1][in] == -1)
            printf("impossible\n");
        else
            printf("%lld\n", dp[N - 1][in]);
    }
    return 0;
}