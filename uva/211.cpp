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

const int ROW = 7, COL = 8;
int idx[8][8];
bool vis[60];
int res[10][10];
int input[10][10];
int dirs[2][2] = {{0, 1}, {1, 0}};
int tot;

void init()
{
    int k = 0;
    for (int i = 0; i <= 6; ++i)
    for (int j = i; j <= 6; ++j)
        idx[i][j] = idx[j][i] = ++k;
}

void dfs(int x, int y)
{
    if (x == ROW)
    {
        ++tot;
        FO (i, ROW)
        {
            FO (j, COL)
                printf("%4d", res[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }
    int p = x + (y + 1) / COL;
    int q = (y + 1) % COL;
    if (res[x][y] != -1)
        dfs(p, q);
    else
    {
        FO (i, 2)
        {
            int xx = x + dirs[i][0];
            int yy = y + dirs[i][1];
            if (xx < ROW && yy < COL && res[xx][yy] == -1)
            {
                int id = idx[input[x][y]][input[xx][yy]];
                if (!vis[id])
                {
                    vis[id] = true;
                    res[x][y] = res[xx][yy] = id;
                    dfs(p, q);
                    vis[id] = false;
                    res[x][y] = res[xx][yy] = -1;
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    init();

    for (int t = 1; ; ++t)
    {
        tot = 0;
        memset(res, -1, sizeof(res));
        memset(vis, 0, sizeof(vis));
        FO (i, 7) FO (j, 8)
            if (!(cin >> input[i][j]))
                return 0;
        if (t > 1)
            printf("\n\n\n");
        printf("Layout #%d:\n\n", t);
        FO (i, 7)
        {
            FO (j, 8)
                printf("%4d", input[i][j]);
            printf("\n");
        }
        printf("\nMaps resulting from layout #%d are:\n\n", t);
        dfs(0, 0);
        printf("There are %d solution(s) for layout #%d.\n", tot, t);
    }

    return 0;
}