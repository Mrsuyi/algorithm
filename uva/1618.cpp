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

const int MAXN = 5050;
int N;
int nums[MAXN];

bool solve()
{
    for (int q = 1; q < N; ++q)
    {
        vector<pii> stk;
        for (int r = N - 1; r > q; --r)
        {
            if (nums[r] >= nums[q])
                continue;
            if (stk.empty() || nums[r] > stk.back().second)
                stk.push_back({nums[r], nums[r]});
            else if (nums[r] < stk.back().first)
            {
                stk.back().first = nums[r];
                while (stk.size() > 1 && stk.back().first <= stk[stk.size() - 2].first)
                {
                    stk[stk.size() - 2] = stk.back();
                    stk.pop_back();
                }
            }
        }
        for (int p = 0; p < q; ++p)
        {
            auto it = lower_bound(stk.begin(), stk.end(), pii(nums[p], nums[p]));
            if (it != stk.begin() && prev(it)->second > nums[p])
                return true;
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        cin >> N;
        FO (i, N)
            scanf("%d", &nums[i]);
        bool res = solve();
        if (!res)
        {
            reverse(nums, nums + N);
            res = solve();
        }
        printf("%s\n", res ? "YES" : "NO");
    }
    return 0;
}