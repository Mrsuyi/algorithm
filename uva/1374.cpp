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
inline int gcd(int a, int b) { if (a < b) return gcd(b, a); return b == 0 ? a : gcd(b, a % b); }

int N, maxd, nums[32] = {1}, maxs[32] = {1};

bool ok(int d)
{
    if (d == maxd)
        return nums[d] == N;
    if (maxs[d] * pow(2, maxd - d) < N)
        return false;
    if (nums[d] < N)
    {
        for (int i = d; i >= 0; --i)
        {
            int val = nums[d] + nums[i];
            if (!count(nums, nums + d + 1, val))
            {
                nums[d + 1] = val;
                maxs[d + 1] = val;
                if (ok(d + 1))
                    return true;
            }
        }
    }
    for (int i = d; i >= 0; --i)
    {
        int val = nums[d] - nums[i];
        if (!count(nums, nums + d + 1, val))
        {
            nums[d + 1] = val;
            maxs[d + 1] = maxs[d];
            if (ok(d + 1))
                return true;
        }
    }
    return false;
}

int main()
{
    while (cin >> N && N)
    {
        for (maxd = 0; ; ++maxd)
        {
            if (ok(0))
            {
                cout << maxd << endl;
                break;
            }
        }
    }
    return 0;
}