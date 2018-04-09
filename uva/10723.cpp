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
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 33;
string s1, s2;
int dpl[MAXN][MAXN], dpc[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    scanf("%d\n", &O);
    FO (o, O)
    {
        getline(cin, s1);
        getline(cin, s2);
        memset(dpl, INF, sizeof(dpl));
        memset(dpc, 0, sizeof(dpc));
        dpl[0][0] = 0;
        dpc[0][0] = 1;
        for (int i = 1; i <= s1.size(); ++i)
        {
            dpl[i][0] = i;
            dpc[i][0] = 1;
        }
        for (int j = 1; j <= s2.size(); ++j)
        {
            dpl[0][j] = j;
            dpc[0][j] = 1;
        }

        for (int i = 1; i <= s1.size(); ++i)
        {
            for (int j = 1; j <= s2.size(); ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dpl[i][j] = dpl[i - 1][j - 1] + 1;
                    dpc[i][j] = dpc[i - 1][j - 1];
                }
                else
                {
                    if (dpl[i - 1][j] < dpl[i][j - 1])
                    {
                        dpl[i][j] = dpl[i - 1][j] + 1;
                        dpc[i][j] = dpc[i - 1][j];
                    }
                    else if (dpl[i - 1][j] > dpl[i][j - 1])
                    {
                        dpl[i][j] = dpl[i][j - 1] + 1;
                        dpc[i][j] = dpc[i][j - 1];
                    }
                    else
                    {
                        dpl[i][j] = dpl[i][j - 1] + 1;
                        dpc[i][j] = dpc[i - 1][j] + dpc[i][j - 1];
                    }
                }
            }
        }
        printf("Case #%d: %d %d\n", o + 1, dpl[s1.size()][s2.size()], dpc[s1.size()][s2.size()]);
    }
    return 0;
}