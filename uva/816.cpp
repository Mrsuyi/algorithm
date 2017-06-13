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

int sx, sy, sd, dx, dy, dd;
int chr2dir[128];
int chr2off[128];
int dir2len[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool can[11][11][4][4];
bool vis[11][11][4];
struct Pos
{
    int x, y, dir;
    Pos() {}
    Pos(int x, int y, int dir) : x(x), y(y), dir(dir) {}
};
Pos parent[11][11][4];
Pos que[1000100];
int l, r;

int main()
{
    chr2dir['N'] = 0;
    chr2dir['E'] = 1;
    chr2dir['S'] = 2;
    chr2dir['W'] = 3;

    chr2off['L'] = -1;
    chr2off['F'] = 0;
    chr2off['R'] = 1;

    string name;
    while (cin >> name)
    {
        if (name == "END")
            break;
        memset(can, 0, sizeof(can));
        memset(vis, 0, sizeof(vis));
        memset(parent, 0, sizeof(parent));
        char chr;
        cin >> sx >> sy >> chr >> dx >> dy;
        sd = chr2dir[chr];
        int x, y;
        while (cin >> x)
        {
            if (x == 0)
                break;
            cin >> y;
            string s;
            while (cin >> s)
            {
                if (s == "*")
                    break;
                int dir = chr2dir[s[0]];
                for (int i = 1; i < s.size(); ++i)
                {
                    int newdir = (dir + chr2off[s[i]] + 4) % 4;
                    can[x][y][dir][newdir] = true;
                }
            }
        }
        // search
        que[0] = Pos(sx, sy, sd);
        vis[sx][sy][sd] = 0;
        for (l = 0, r = 1; l < r; ++l)
        {
            Pos cur = que[l];
            int x = cur.x, y = cur.y, dir = cur.dir;
            int p = cur.x + dir2len[dir][0];
            int q = cur.y + dir2len[dir][1];
            if (p == dx && q == dy)
            {
                dd = dir;
                parent[dx][dy][dd] = cur;
                break;
            }
            FO (i, 4)
                if (can[p][q][dir][i] && !vis[p][q][i])
                {
                    que[r++] = Pos(p, q, i);
                    parent[p][q][i] = cur;
                    vis[p][q][i] = true;
                }
        }
        // res
        cout << name << endl;
        if (l < r)
        {
            vector<Pos> path;
            Pos cur(dx, dy, dd);
            while (cur.x != 0)
            {
                path.push_back(cur);
                cur = parent[cur.x][cur.y][cur.dir];
            }
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i += 10)
            {
                printf(" ");
                for (int j = 0; j < 10 && i + j < path.size(); ++j)
                    printf(" (%d,%d)", path[i + j].x, path[i + j].y);
                printf("\n");
            }
        }
        else
        {
            printf("  No Solution Possible\n");
        }
    }
    return 0;
}