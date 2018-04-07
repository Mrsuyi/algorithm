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
#define fi first
#define se second
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 110;
int N;
string s;
string dp[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> s)
    {
        N = s.size();
        for (int i = 1; i <= N; ++i)
        {
            for (int l = 0, r = l + i - 1; r < N; ++l, ++r)
            {
                dp[l][r] = s.substr(l, i);
                for (int k = 1; k <= i; ++k)
                {
                    string dup = s.substr(l, k);
                    int cnt = 1;
                    while (true)
                    {
                        string head = (cnt <= 1) ? dp[l][l + k - 1] : (to_string(cnt) + '(' + dp[l][l + k - 1] + ')');
                        string tail = dp[l + cnt * k][r];
                        string tot = head + tail;
                        if (dp[l][r].size() > tot.size())
                            dp[l][r] = tot;
                        if ((l + cnt * k + k - 1) > r || (s.substr(l + cnt * k, k) != dup))
                            break;
                        ++cnt;
                    }
                }
            }
        }
        printf("%s\n", dp[0][N - 1].data());
    }
    return 0;
}