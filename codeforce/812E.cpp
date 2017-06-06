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

const int MAXN = 100100;
const int MAXA = 18000000;

int N;
int head[MAXN], val[MAXN], nxt[MAXN], d[MAXN], dup[MAXA][2];

void dfs(int cur)
{
    for (int child = head[cur]; child != -1; child = nxt[child])
        dfs(child);
    if (head[cur] != -1)
        d[cur] = !d[head[cur]];
    else
        d[cur] = 0;
    ++dup[val[cur]][d[cur]];
}

int main()
{
    while (cin >> N)
    {
        memset(head, -1, sizeof(head));
        memset(nxt, -1, sizeof(nxt));
        memset(dup, 0, sizeof(dup));
        FO (i, N) cin >> val[i];
        FOR (i, 1, N)
        {
            int parent;
            cin >> parent;
            --parent;
            nxt[i] = head[parent];
            head[parent] = i;
        }
        dfs(0);
        llong all = 0, cnt[2] = {0};
        FO (i, N)
        {
            if (!d[i])
                all ^= val[i];
            ++cnt[d[i]];
        }
        llong res = 0;
        if (all == 0)
        {
            res = cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2;
            FO (i, MAXA)
                res += (llong)dup[i][0] * dup[i][1];
        }
        else
        {
            FO (i, N)
                if (d[i])
                    res += dup[all ^ val[i]][0];
        }
        cout << res << endl;
    }
    return 0;
}