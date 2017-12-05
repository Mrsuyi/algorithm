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
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7fffff7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 1000100, MAXK = 110;
int N, M, K;
int nums[MAXN] = {0, 1, 2, 3}, cnt[MAXK];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        cin >> N >> M >> K;
        memset(cnt, 0, sizeof(cnt));
        if (K <= 3)
        {
            printf("Case %d: %d\n", o + 1, K);
            continue;
        }
        cnt[1] = cnt[2] = cnt[3] = 1;
        int l = 1, tot = 3, res = INT_MAX;
        for (int i = 4; i <= N; ++i)
        {
            nums[i] = (nums[i - 1] + nums[i - 2] + nums[i - 3]) % M + 1;
            if (nums[i] > K)
                continue;
            if (++cnt[nums[i]] == 1)
            {
                if (++tot >= K)
                {
                    for (;; ++l)
                    {
                        if (nums[l] > K)
                            continue;
                        if (--cnt[nums[l]] == 0)
                            break;
                    }
                    --tot;
                    res = min(res, i - l + 1);
                    ++l;
                }
            }
        }
        if (res == INT_MAX)
            printf("Case %d: sequence nai\n", o + 1);
        else
            printf("Case %d: %d\n", o + 1, res);
    }
    return 0;
}