#include <climits>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
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

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int N;
int nums[5050];
int first[5050], last[5050];
int dp[5050];

int main()
{
    while (cin >> N)
    {
        memset(first, -1, sizeof(first));
        memset(last, 0, sizeof(last));
        memset(dp, 0, sizeof(dp));
        FO (i, N)
        {
            cin >> nums[i];
            if (first[nums[i]] == -1)
                first[nums[i]] = i;
            last[nums[i]] = i;
        }
        FO (i, N)
        {
            if (i > 0)
                dp[i] = dp[i - 1];
            int l = first[nums[i]];
            for (int j = i, val = 0; j >= l; --j)
            {
                if (last[nums[j]] > i)
                    break;
                l = min(l, first[nums[j]]);
                if (j == last[nums[j]])
                    val ^= nums[j];
                if (j == l)
                {
                    dp[i] = max(dp[i], val + (l > 0 ? dp[l - 1] : 0));
                    break;
                }
            }
        }
        printf("%d\n", dp[N - 1]);
    }
    return 0;
}