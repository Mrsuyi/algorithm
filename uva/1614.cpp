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

const int MAXN = 100100;
int N;
pii nums[MAXN];
int res[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N)
    {
        memset(res, -1, sizeof(res));
        llong half = 0;
        FO (i, N)
        {
            scanf("%d", &nums[i].first);
            nums[i].second = i;
            half += nums[i].first;
        }
        if (half & 1)
        {
            printf("No\n");
            continue;
        }
        sort(nums, nums + N);
        half /= 2;
        llong sum = 0;
        for (int i = N - 1; sum < half; --i)
        {
            if (sum + nums[i].first <= half)
            {
                sum += nums[i].first;
                res[nums[i].second] = 1;
            }
        }
        printf("Yes\n");
        for (int i = 0; i < N; ++i)
        {
            if (i) printf(" ");
            printf("%d", res[i]);
        }
        printf("\n");
    }
    return 0;
}