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

const int ROW = 4, COL = 6;
bool input[ROW + 3][COL + 3][2], mp[ROW + 3][COL + 3][2], vis[ROW + 3][COL + 3];
char dirs[4] = {'N', 'W', 'S', 'E'};
int step[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int cur[4][2] = {{0, 0}, {0, 0}, {1, 0}, {0, 1}};
int wall[4] = {0, 1, 0, 1};
string path;

bool dfs(int x, int y, int d)
{
    if (x <= 0 || x > ROW || y <= 0 || y > COL)
        return true;
    if (min(x + 1, ROW - x) + min(y + 1, COL - y) > d)
        return false;
    for (int i = 0; i < 4; ++i)
    {
        int p = x + cur[i][0], q = y + cur[i][1];
        int xx = x + step[i][0], yy = y + step[i][1];
        if (vis[xx][yy])
            continue;
        int w = wall[i];
        if (!mp[p][q][w])
        {
            vis[xx][yy] = true;
            path.push_back(dirs[i]);
            if (dfs(xx, yy, d - 1))
                return true;
            path.pop_back();
            vis[xx][yy] = false;
        }
        else
        {
            int pp = p + step[i][0], qq = q + step[i][1];
            if (xx >= 1 && xx <= ROW && yy >= 1 && yy <= COL && !mp[pp][qq][w])
            {
                path.push_back(dirs[i]);
                vis[xx][yy] = true;
                mp[p][q][w] = false;
                mp[pp][qq][w] = true;
                if (dfs(xx, yy, d - 1))
                    return true;
                mp[pp][qq][w] = false;
                mp[p][q][w] = true;
                vis[xx][yy] = false;
                path.pop_back();
            }
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y;
    while ((cin >> y >> x) && x && y)
    {
        memset(input, 0, sizeof(input));
        for (int i = 1; i <= ROW; ++i)
        for (int j = 1; j <= COL; ++j)
        {
            int wa;
            cin >> wa;
            input[i][j][1] = wa & (1 << 0);
            input[i][j][0] = wa & (1 << 1);
            input[i][j + 1][1] = wa & (1 << 2);
            input[i + 1][j][0] = wa & (1 << 3);
        }
        for (int d = 0; ; ++d)
        {
            memcpy(mp, input, sizeof(input));
            memset(vis, 0, sizeof(vis));
            path = "";
            if (dfs(x, y, d))
            {
                cout << path << endl;
                break;
            }
        }
    }
    return 0;
}