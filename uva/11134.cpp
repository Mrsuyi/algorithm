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

const int MAXN = 5050;
int N;
int range[MAXN][4];
int idxs[MAXN];
int res[MAXN][2];
bool vis[MAXN][2];

bool cmpx(const int a, const int b)
{
    return range[a][2] < range[b][2];
}
bool cmpy(const int a, const int b)
{
    return range[a][3] < range[b][3];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N && N)
    {
        FO (i, N)
        {
            cin >> range[i][0] >> range[i][1] >> range[i][2] >> range[i][3];
            idxs[i] = i;
        }
        memset(vis, 0, sizeof(vis));
        sort(idxs, idxs + N, cmpx);
        FO (i, N)
        {
            int idx = idxs[i];
            int j;
            for (j = range[idx][0]; j <= range[idx][2]; ++j)
            {
                if (!vis[j][0])
                {
                    vis[j][0] = true;
                    res[idx][0] = j;
                    break;
                }
            }
            if (j > range[idx][2])
            {
                printf("IMPOSSIBLE\n");
                goto end;
            }
        }

        sort(idxs, idxs + N, cmpy);
        FO (i, N)
        {
            int idx = idxs[i];
            int j;
            for (j = range[idx][1]; j <= range[idx][3]; ++j)
            {
                if (!vis[j][1])
                {
                    vis[j][1] = true;
                    res[idx][1] = j;
                    break;
                }
            }
            if (j > range[idx][3])
            {
                printf("IMPOSSIBLE\n");
                goto end;
            }
        }
        FO (i, N)
            printf("%d %d\n", res[i][0], res[i][1]);
        end:;
    }
    return 0;
}