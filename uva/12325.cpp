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

int T;
llong N, S1, V1, S2, V2;

int main()
{
    cin >> T;
    FO (t, T)
    {
        cin >> N >> S1 >> V1 >> S2 >> V2;
        if (S1 < S2)
        {
            swap(S1, S2);
            swap(V1, V2);
        }
        llong res = 0;
        if (S1 * S1 < N)
        {
            if (S2 * V1 > S1 * V2)
            {
                for (llong i = 0; i < S1; ++i)
                    res = max(res, i * V2 + (N - i * S2) / S1 * V1);
            }
            else
            {
                for (llong i = 0; i < S2; ++i)
                    res = max(res, i * V1 + (N - i * S1) / S2 * V2);
            }
        }
        else
        {
            for (llong i = 0; i <= N / S1; ++i)
                res = max(res, i * V1 + (N - i * S1) / S2 * V2);
        }
        printf("Case #%d: %lld\n", t + 1, res);
    }
    return 0;
}