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

const int MAXN = 12;
int tot, N, M, NM;
bool in[MAXN][MAXN];
int row[MAXN], col[MAXN], dial[MAXN * 2], diar[MAXN * 2];

bool ok()
{
    FO (i, N) FO (j, M)
        if (in[i][j] && !row[i] && !col[j] && !diar[i + j] && !dial[M - (j - i)])
            return false;
    return true;
}

bool idax(int d, int idx)
{
    if (d == 0)
        return ok();
    if (NM - idx < d)
        return false;
    int x = idx / M;
    int y = idx % M;
    ++row[x], ++col[y], ++diar[x + y], ++dial[M - (y - x)];
    if (idax(d - 1, idx + 1))
        return true;
    --row[x], --col[y], --diar[x + y], --dial[M - (y - x)];
    return idax(d, idx + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int t = 1; cin >> N >> M && N; ++t)
    {
        string s;
        NM = N * M;
        FO (i, N)
        {
            cin >> s;
            FO (j, M)
                in[i][j] = s[j] == 'X';
        }
        for (int d = 0; ; ++d)
        {
            memset(row, 0, sizeof(row));
            memset(col, 0, sizeof(col));
            memset(dial, 0, sizeof(dial));
            memset(diar, 0, sizeof(diar));
            if (idax(d, 0))
            {
                printf("Case %d: %d\n", t, d);
                break;
            }
        }
    }
    return 0;
}