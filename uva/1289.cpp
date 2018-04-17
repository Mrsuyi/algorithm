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
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7;
double EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 55, MAXH = 55;
int N, K;
vector<int> vals[MAXN];
unordered_set<int> has[MAXN];
vector<int> nums;
int dp[MAXN * MAXH][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int o = 1; cin >> N; ++o)
    {
        nums.clear();
        FO (i, N)
        {
            int h;
            cin >> h;
            vals[i] = vector<int>(h);
            has[i].clear();
            FO (j, h)
            {
                cin >> vals[i][j];
                has[i].insert(vals[i][j]);
                nums.push_back(vals[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        K = unique(nums.begin(), nums.end()) - nums.begin();
        FO (i, N)
            dp[0][i] = 1;
        FO (i, K)
        {
            int cnt = 0, num = nums[i];
            FO (j, N)
                cnt += has[j].count(num);
            FO (j, N)
            {
                dp[i + 1][j] = INF;
                if (!has[j].count(num))
                    continue;
                FO (k, N)
                {
                    if (j != k)
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + cnt - int(has[k].count(num)));
                    else
                        dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + (cnt == 1 ? 0 : cnt));
                }
            }
        }
        int res = INF;
        FO (i, N)
            res = min(res, dp[K][i]);
        printf("Case %d: %d\n", o, (res - N) * 2 + N - 1);
    }
    return 0;
}