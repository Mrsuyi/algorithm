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
typedef array<int, 2> pii;
typedef array<double, 2> pdd;
typedef array<llong, 2> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9+7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

int N, target, res;
int nums[10];

bool dfs(int remain)
{
    int cnt = 0;
    for (int i = 0; i < N - 1; ++i)
        if (nums[i] + 1 != nums[i + 1])
            ++cnt;
    if (cnt == 0)
        return true;
    if (cnt > remain * 3)
        return false;
    int cur[10];
    memcpy(cur, nums, sizeof(int) * N);
    for (int i = 0; i < N; ++i)
    {
        if (i && nums[i - 1] + 1 == nums[i])
            continue;
        for (int j = i + 1; j <= N; ++j)
        {
            if (j < N && nums[j - 1] + 1 == nums[j])
                continue;
            int cut[10];
            memcpy(cut, nums + i, sizeof(int) * (j - i));
            for (int k = j + 1; k <= N; ++k)
            {
                if (k < N && nums[k - 1] + 1 == nums[k])
                    continue;
                memcpy(nums + i, nums + j, sizeof(int) * (k - j));
                memcpy(nums + i + k - j, cut, sizeof(int) * (j - i));
                if (dfs(remain - 1))
                    return true;
                memcpy(nums, cur, sizeof(int) * N);
            }
        }
    }
    return false;
}

int main()
{
    for (int t = 1; cin >> N && N; ++t)
    {
        FO (i, N)
            cin >> nums[i];
        int res = -1;
        for (int i = 0; i < N && res == -1; ++i)
            if (dfs(i))
                res = i;
        printf("Case %d: %d\n", t, res);
    }
    return 0;
}