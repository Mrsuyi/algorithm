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
string s;
int N, L;
double sums[MAXN] = {0}, cans[MAXN];

int cmp(int a, int b, int c, int d)
{
    return (sums[b] - sums[a]) * (d - c) - (sums[d] - sums[c]) * (b - a);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        cin >> N >> L >> s;
        FO (i, N)
            sums[i + 1] = sums[i] + (s[i] == '1');

        int resl = 0, resr = L;
        int i = 0, j = 0;
        for (int k = L; k <= N; ++k)
        {
            while (j - i > 1 && cmp(cans[j - 1], k - L, cans[j - 2], cans[j - 1]) <= 0) --j;
            cans[j++] = k - L;
            while (j - i > 1 && cmp(cans[i], k, cans[i + 1], k) <= 0) ++i;
            int res = cmp(cans[i], k, resl, resr);
            if (res > 0 || (res == 0 && k - cans[i] < resr - resl))
            {
                resl = cans[i];
                resr = k;
            }
        }
        printf("%d %d\n", resl + 1, resr);
    }
    return 0;
}