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
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 7;
const int MAXS = MAXN * MAXN * MAXN;
const int MAXE = 2 * MAXN * (MAXN + 1);
int N, K, tot;
int sall[MAXS], shas[MAXS];
vector<int> s2e[MAXS];
vector<int> e2s[MAXE];

int e_hori(int x, int y)
{
    return (2 * N + 1) * x + y + 1;
}
int e_vert(int x, int y)
{
    return (2 * N + 1) * x + y + N + 1;
}

void build()
{
    FO (i, 2 * N * (N + 1))
        e2s[i].clear();
    tot = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int x = 0; x <= N - i; ++x)
        for (int y = 0; y <= N - i; ++y)
        {
            sall[tot] = shas[tot] = 4 * i;
            s2e[tot].clear();
            for (int j = 0; j < i; ++j)
            {
                int a = e_hori(x, y + j);
                int b = e_vert(x + j, y);
                int c = e_hori(x + i, y + j);
                int d = e_vert(x + j, y + i);
                e2s[a].push_back(tot);
                e2s[b].push_back(tot);
                e2s[c].push_back(tot);
                e2s[d].push_back(tot);
                s2e[tot].push_back(a);
                s2e[tot].push_back(b);
                s2e[tot].push_back(c);
                s2e[tot].push_back(d);
            }
            ++tot;
        }
    }
    FO (k, K)
    {
        int e;
        cin >> e;
        for (int s : e2s[e])
            --shas[s];
    }
}

bool ok(int d)
{
    int sqr = -1;
    for (int i = 0; i < tot && sqr == -1; ++i)
        if (sall[i] == shas[i])
            sqr = i;
    if (sqr == -1)
        return true;
    if (d == 0)
        return false;
    for (int e : s2e[sqr])
    {
        for (int s : e2s[e])
            --shas[s];
        if (ok(d - 1))
            return true;
        for (int s : e2s[e])
            ++shas[s];
    }
    return false;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        cin >> N >> K;
        build();
        for (int d = 0; ; ++d)
        {
            if (ok(d))
            {
                cout << d << endl;
                break;
            }
        }
    }
    return 0;
}