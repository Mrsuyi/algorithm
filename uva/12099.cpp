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

const int MAXN = 75, MAXW = 2120;
int N;
int dp[MAXN][MAXW][MAXW];
pii books[MAXN];

void update(int& a, int b)
{
    if (a == -1 || a > b)
        a = b;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    scanf("%d", &O);
    FO (o, O)
    {
        scanf("%d", &N);
        FO (i, N)
            scanf("%d %d", &books[i].first, &books[i].second);
        sort(books, books + N, greater<pii>());
        // first book on second shelf
        memset(dp[0], -1, sizeof(dp[0]));
        dp[0][0][0] = 0;
        int tot = 0;
        FO (i, N)
        {
            int h = books[i].first, w = books[i].second;
            memset(dp[i + 1], -1, sizeof(dp[i + 1]));
            for (int w1 = tot; w1 >= 0; --w1)
            for (int w2 = tot - w1; w2 >= 0; --w2)
            {
                if (dp[i][w1][w2] != -1)
                {
                    update(dp[i + 1][w1 + w][w2], dp[i][w1][w2] + (w1 ? 0 : h));
                    update(dp[i + 1][w1][w2 + w], dp[i][w1][w2] + (w2 ? 0 : h));
                    update(dp[i + 1][w1][w2], dp[i][w1][w2]);
                }
            }
            tot += w;
        }
        int res = INT_MAX;
        for (int w1 = tot; w1 > 0; --w1)
        for (int w2 = tot - w1; w2 > 0; --w2)
            if (dp[N][w1][w2] != -1)
                res = min(res, (books[0].first + dp[N][w1][w2]) * max(tot - w1 - w2, max(w1, w2)));
        printf("%d\n", res);
    }
    return 0;
}