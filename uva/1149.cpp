#include <algorithm>
#include <array>
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
int N, L;
int nums[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        if (t)
            printf("\n");
        cin >> N >> L;
        FO (i, N)
            cin >> nums[i];
        sort(nums, nums + N);
        int res = 0;
        int i, j;
        for (i = 0, j = N - 1; i < j; --j, ++res)
        {
            if (nums[i] + nums[j] <= L)
                ++i;
        }
        res += i == j;
        printf("%d\n", res);
    }
    return 0;
}