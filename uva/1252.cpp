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

const int MAXM = 12, MAXN = 130;
int M, N;
char num[MAXM];
int nums[MAXN], dp[1 << MAXM][1 << MAXM];

void init()
{
    for (int i = 0; i < (1 << M); ++i)
    {
        int j = i;
        while (true)
        {
            int cnt = 0;
            for (int k = 0; k < N && cnt < 2; ++k)
                cnt += (nums[k] & i) == j;
            dp[i][j] = cnt < 2 ? 0 : INF;
            if (j == 0)
                break;
            j = (j - 1) & i;
        }
    }
}

int work(int a, int b)
{
    if (dp[a][b] == INF)
    {
        for (int i = 0; i < M; ++i)
        {
            if (a & (1 << i))
                continue;
            dp[a][b] = min(dp[a][b], max(work(a | (1 << i), b), work(a | (1 << i), b | (1 << i))) + 1);
        }
    }
    return dp[a][b];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%d %d", &M, &N) && M)
    {
        FO (i, N)
        {
            scanf("%s", num);
            nums[i] = 0;
            FO (j, M)
                nums[i] |= (num[j] == '1') << j;
        }
        init();
        printf("%d\n", work(0, 0));
    }
    return 0;
}
