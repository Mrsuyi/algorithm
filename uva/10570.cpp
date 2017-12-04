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

const int MAXN = 540;
int N;
int nums[MAXN], tar[MAXN], vis[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N && N)
    {
        FO (i, N)
        {
            int num;
            scanf("%d", &num);
            nums[i] = num - 1;
        }
        int res = INT_MAX;
        for (int r : {-1, 1})
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0, k = i; j < N; ++j, k = (k + r + N) % N)
                tar[j] = k;

            memset(vis, 0, sizeof(vis));
            int swp = 0;
            FO (j, N)
            {
                if (j == tar[nums[j]] || vis[j])
                    continue;
                int cur = j, cnt = 0;
                while (!vis[cur])
                {
                    vis[cur] = true;
                    cur = nums[tar[cur]];
                    ++cnt;
                }
                swp += cnt - 1;
            }
            res = min(res, swp);
        }
        printf("%d\n", res);
    }
    return 0;
}