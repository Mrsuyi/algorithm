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

int N, M, K;
const int MAXN = 10010;
bool lit[MAXN][MAXN];
int grp[MAXN][MAXN];
bool can[MAXN][MAXN];
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<int> rows[MAXN], cols[MAXN];
int tot;

void dfs(int x, int y)
{
    FO (i, 4)
    {
        int p = x + dirs[i][0];
        int q = y + dirs[i][1];
        if (p >= 0 && p < N && q >= 0 && q <= M && lit[p][q] && grp[p][q] == -1)
        {
            grp[p][q] = grp[x][y];
            dfs(p, q);
        }
    }
}
void group()
{
    FO (i, N) FO (j, M)
    {
        if (grp[i][j] == -1 && lit[i][j])
        {
            grp[i][j] = tot++;
            dfs(i, j);
        }
    }
}
void reach()
{
    
}

int main()
{
    while (cin >> N >> M >> K)
    {
        memset(lit, 0, sizeof(lit));
        memset(grp, -1, sizeof(grp));
        memset(can, 0, sizeof(can));
        FO (i, N)
            rows[i].clear();
        FO (i, M)
            cols[i].clear();
        tot = 0;
        FO (i, K)
        {
            int x, y;
            --x, --y;
            cin >> x >> y;
            lit[x][y] = true;
        }
        group();
        reach();
        go();
    }
    return 0;
}