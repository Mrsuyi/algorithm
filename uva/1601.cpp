#include <algorithm>
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
#ifdef __GNUC__
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#else
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#endif
#else
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXW = 20;
char mat[MAXW][MAXW];
int W, H, N;
int idx[20][20], tot;
int vis[200][200][200];
int src[5], dst[5];
vector<int> edges[200];
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs()
{
    vector<vector<int>> v1, v2;
    int m1 = 1, m2 = 2;
    v1.push_back({src[0], src[1], src[2]});
    v2.push_back({dst[0], dst[1], dst[2]});
    vis[src[0]][src[1]][src[2]] |= m1;
    vis[dst[0]][dst[1]][dst[2]] |= m2;
    for (int res = 0; ; ++res)
    {
        vector<vector<int>> nxt;
        for (int p = 0; p < v1.size(); ++p)
        {
            int a1 = v1[p][0], a2 = v1[p][1], a3 = v1[p][2];
            if (vis[a1][a2][a3] & m2)
                return res;
            for (int i = 0; i < edges[a1].size(); ++i)
            {
                for (int j = 0; j < edges[a2].size(); ++j)
                {
                    for (int k = 0; k < edges[a3].size(); ++k)
                    {
                        int b1 = edges[a1][i], b2 = edges[a2][j], b3 = edges[a3][k];
                        // visited
                        if (vis[b1][b2][b3] & m1)
                            continue;
                        // collision
                        if ((b1 == b2) || (b1 == b3) || (b2 && b2 == b3))
                            continue;
                        // swap
                        if ((b1 == a2 && b2 == a1) ||
                            (b1 == a3 && b3 == a1) ||
                            (b2 && b2 == a3 && b3 == a2))
                            continue;
                        vis[b1][b2][b3] |= m1;
                        nxt.push_back({b1, b2, b3});
                    }
                }
            }
        }
        swap(v1, nxt);
        if (v1.size() > v2.size())
        {
            swap(v1, v2);
            swap(m1, m2);
        }
    }
    return -1;
}

int main()
{
    edges[0] = {0};
    while (scanf("%d %d %d\n", &W, &H, &N))
    {
        if (W == 0)
            break;
        FO (i, H)
            fgets(mat[i], MAXW, stdin);
        memset(vis, 0, sizeof(vis));
        tot = 1;
        FO (i, H) FO (j, W)
        {
            if (mat[i][j] != '#')
            {
                idx[i][j] = tot;
                edges[tot] = {tot};
                ++tot;
            }
        }
        memset(src, 0, sizeof(src));
        memset(dst, 0, sizeof(dst));
        FO (i, H) FO (j, W)
        {
            if (isalpha(mat[i][j]))
            {
                if (islower(mat[i][j]))
                    src[mat[i][j] - 'a'] = idx[i][j];
                else
                    dst[mat[i][j] - 'A'] = idx[i][j];
            }
            if (mat[i][j] != '#')
            {
                int u = idx[i][j];
                for (int k = 0; k < 4; ++k)
                {
                    if (mat[i + dirs[k][0]][j + dirs[k][1]] != '#')
                    {
                        int v = idx[i + dirs[k][0]][j + dirs[k][1]];
                        edges[u].push_back(v);
                        edges[v].push_back(u);
                    }
                }
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}