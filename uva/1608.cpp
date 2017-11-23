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
const int INF = 0x0fffffff, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 200200;
int N;
int nums[MAXN], l[MAXN], r[MAXN];

bool ok(int bgn, int end)
{
    if (bgn >= end)
        return true;
    for (int i = bgn, j = end; i <= j; ++i, --j)
    {
        if (l[i] < bgn && r[i] > end)
            return ok(bgn, i - 1) && ok(i + 1, end);
        if (i == j)
            break;
        if (l[j] < bgn && r[j] > end)
            return ok(bgn, j - 1) && ok(j + 1, end);
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        cin >> N;
        FO (i, N)
            cin >> nums[i];
        unordered_map<int, int> st;
        FO (i, N)
        {
            l[i] = st.count(nums[i]) ? st[nums[i]] : -1;
            st[nums[i]] = i;
        }
        st.clear();
        RFO (i, N)
        {
            r[i] = st.count(nums[i]) ? st[nums[i]] : N;
            st[nums[i]] = i;
        }
        printf("%s\n", ok(0, N - 1) ? "non-boring" : "boring");
    }
    return 0;
}