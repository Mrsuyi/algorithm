#include <algorithm>
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

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

struct Node
{
    int l, r;
} neib[100100];
int N, M;

void link(int l, int r)
{
    neib[l].r = r;
    neib[r].l = l;
}

int main()
{
    for (int t = 1; cin >> N >> M; ++t)
    {
        bool inv = false;
        FO (i, N)
        {
            neib[i + 1].l = i;
            neib[i + 1].r = i + 2;
        }
        neib[0].r = 1;
        FO (m, M)
        {
            int cmd, a, b, al, ar, bl, br;
            cin >> cmd;
            if (cmd != 4)
            {
                cin >> a >> b;
                al = neib[a].l, ar = neib[a].r;
                bl = neib[b].l, br = neib[b].r;
            }
            if (cmd < 3 && inv)
                cmd = 3 - cmd;
            if (cmd == 3)
            {
                // ba
                if (al == b)
                    cmd = 1;
                // ab
                else if (ar == b)
                    cmd = 2;
            }
            switch (cmd)
            {
                case 1:
                    if (ar == b)
                        break;
                    link(al, ar);
                    link(bl, a);
                    link(a, b);
                    break;
                case 2:
                    if (br == a)
                        break;
                    link(al, ar);
                    link(b, a);
                    link(a, br);
                    break;
                case 3:
                    link(al, b);
                    link(b, ar);
                    link(bl, a);
                    link(a, br);
                    break;
                case 4:
                    inv = !inv;
                    break;
                default:;
            }
        }
        llong res = 0;
        int cur = 0;
        for (int i = 0; i <= N; ++i)
        {
            if (i & 1)
                res += cur;
            cur = neib[cur].r;
        }
        if (inv && N % 2 == 0)
            res = (1LL + N) * N / 2 - res;
        printf("Case %d: %lld\n", t, res);
    }
    return 0;
}