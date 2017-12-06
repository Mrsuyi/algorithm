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

// const int MAXN = 100100;
// llong N, res, resl, resr;
// pll nums[MAXN];
// llong sums[MAXN] = {0};

// bool cmp(const pll& lhs, const pll& rhs)
// {
//     return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
// }

// int main()
// {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     for (int o = 0; cin >> N; ++o)
//     {
//         if (o)
//             printf("\n");
//         res = LLONG_MIN;
//         for (int i = 1; i <= N; ++i)
//         {
//             scanf("%lld", &nums[i].first);
//             nums[i].second = i;
//             sums[i] = sums[i - 1] + nums[i].first;
//         }
//         sort(nums + 1, nums + N + 1, cmp);
//         set<llong> idxs = {0, N + 1};
//         for (llong i = 1; i <= N; ++i)
//         {
//             auto itr = idxs.lower_bound(nums[i].second), itl = prev(itr);
//             llong val = nums[i].first * (sums[*itr - 1] - sums[*itl]);
//             if (val >= res)
//             {
//                 res = val;
//                 resl = *itl + 1;
//                 resr = *itr - 1;
//             }
//             idxs.insert(nums[i].second);
//         }
//         printf("%lld\n%lld %lld\n", res, resl, resr);
//     }
//     return 0;
// }

const int MAXN = 100100;
int N, resl, resr;
int l[MAXN], r[MAXN];
llong nums[MAXN], sums[MAXN] = {0}, res;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int o = 0; cin >> N; ++o)
    {
        if (o)
            printf("\n");
        res = LLONG_MIN;
        nums[0] = nums[N + 1] = LLONG_MIN;
        for (int i = 1; i <= N; ++i)
        {
            scanf("%lld", &nums[i]);
            sums[i] = sums[i - 1] + nums[i];
            l[i] = i - 1;
            r[i] = i + 1;
        }
        for (int i = 1; i <= N; ++i)
            while (nums[l[i]] >= nums[i]) l[i] = l[l[i]];
        for (int i = N; i >= 1; --i)
            while (nums[r[i]] >= nums[i]) r[i] = r[r[i]];
        for (int i = 1; i <= N; ++i)
        {
            llong val = (sums[r[i] - 1] - sums[l[i]]) * nums[i];
            if (val > res)
            {
                res = val;
                resl = l[i] + 1;
                resr = r[i] - 1;
            }
        }
        if (res == 0)
            printf("%lld\n%lld %lld\n", res, resl, resl);
        else
            printf("%lld\n%lld %lld\n", res, resl, resr);
    }
    return 0;
}
