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

int N;
string S, T;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int C;
    cin >> C;
    FO (ca, C)
    {
        cin >> S >> T;
        N = S.size();
        int t0, t1, s0, s1;
        t0 = t1 = s0 = s1 = 0;
        FO (i, N)
        {
            s0 += S[i] == '0';
            s1 += S[i] == '1';
            t0 += T[i] == '0';
            t1 += T[i] == '1';
        }
        int res = 0, chg = 0;
        FO (i, N)
        {
            if (S[i] == '?')
            {
                ++res;
                if (T[i] == '1' && s1 < t1)
                {
                    S[i] = '1';
                    ++s1;
                }
                else
                {
                    S[i] = '0';
                    ++s0;
                }
            }
        }
        FO (i, N)
        {
            if (S[i] == '0' && T[i] == '1' && s1 < t1)
            {
                S[i] = '1';
                ++s1;
                --s0;
                ++res;
            }
        }
        FO (i, N)
            chg += S[i] != T[i];
        res = (s0 == t0 && s1 == t1) ? (res + chg / 2) : -1;
        printf("Case %d: %d\n", ca + 1, res);
    }
    return 0;
}