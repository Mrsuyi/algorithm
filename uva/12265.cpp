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

const int MAXN = 1010;
int N, M;
char mp[MAXN][MAXN];
int h[MAXN];

struct Rec
{
    int l, h;
};
Rec recs[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        cin >> N >> M;
        FO (i, N)
            scanf("%s", mp[i]);
        memset(h, 0, sizeof(h));

        map<int, int> res;
        FO (i, N)
        {
            int top = -1;
            FO (j, M)
            {
                if (mp[i][j] == '#')
                {
                    top = -1;
                    h[j] = 0;
                }
                else
                {
                    ++h[j];
                    Rec cur;
                    cur.l = j;
                    cur.h = h[j];
                    while (top >= 0 && recs[top].h >= h[j])
                        cur.l = recs[top--].l;
                    if (top < 0 || cur.h - cur.l > recs[top].h - recs[top].l)
                        recs[++top] = cur;
                    ++res[2 * (recs[top].h + j - recs[top].l + 1)];
                }
            }
        }
        for (const auto& p : res)
            printf("%d x %d\n", p.second, p.first);
    }
    return 0;
}