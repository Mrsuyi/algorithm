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
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0fffffff, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 100100;
int N, S, nums[MAXN * 2], cnt[MAXN], ok[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(ok, 0, sizeof(ok));
        cin >> S >> N;
        FO (i, N)
            cin >> nums[i];
        int dup = 0, res = 0;
        FO (i, N + S)
        {
            if (i < N && ++cnt[nums[i]] > 1)
                ++dup;
            if (i - S >= 0 && --cnt[nums[i - S]] == 1)
                --dup;
            ok[i] = dup == 0 && (i - S < 0 || ok[i - S]);
            res += i >= N && ok[i - 1];
        }
        printf("%d\n", res);
    }
    return 0;
}