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

const int MAXN = 200200;
int N;
// int nums[MAXN], dp[MAXN];

// con[i] => min ending-number of continuous sequence of length-i
// len[i] => max length of sequence(continuous or not) at nums[i]
int nums[MAXN], con[MAXN], len[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // int Z;
    // cin >> Z;
    // FO (z, Z)
    // {
    //     cin >> N;
    //     FO (i, N)
    //         scanf("%d", &nums[i]);
    //     memset(dp, 0, sizeof(dp));
    //     map<int, int> mp;
    //     mp[nums[0]] = 1;
    //     dp[0] = 1;
    //     int cnt = 1, res = 1;
    //     for (int i = 1; i < N; ++i)
    //     {
    //         if (nums[i] > nums[i - 1])
    //         {
    //             ++cnt;
    //             dp[i] = dp[i - 1] + 1;
    //         }
    //         else
    //             cnt = 1;
    //         auto cur = mp.lower_bound(nums[i]);
    //         if (cur != mp.begin())
    //         {
    //             auto pre = prev(cur);
    //             dp[i] = max(dp[i], pre->second + 1);
    //             if (pre->second < cnt)
    //                 cur = mp.insert(cur, {nums[i], cnt});
    //         }
    //         else
    //             cur = mp.insert(cur, {nums[i], cnt});
    //         auto nxt = next(cur);
    //         while (nxt != mp.end() && nxt->second <= cur->second)
    //             nxt = mp.erase(nxt);
    //         res = max(res, dp[i]);
    //     }
    //     printf("%d\n", res);
    // }

    int Z;
    cin >> Z;
    FO (z, Z)
    {
        cin >> N;
        FO (i, N)
            scanf("%d", &nums[i]);
        int res = 1;
        memset(con, 127, sizeof(con));
        memset(len, 0, sizeof(len));
        con[0] = nums[0];
        len[0] = 1;
        for (int i = 1, cnt = 1; i < N; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                ++cnt;
                len[i] = len[i - 1] + 1;
            }
            else
            {
                cnt = 1;
            }
            int l = lower_bound(con, con + N, nums[i]) - con;
            len[i] = max(len[i], l + 1);
            res = max(res, len[i]);
            con[cnt - 1] = min(con[cnt - 1], nums[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}