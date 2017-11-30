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
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7fffff7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 15;
int N;
int ts[1 << MAXN];
int pre[4][2] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}};
char draw[4] = {'|', '_', '|', '_'};
int nxt[4][2] = {{-1, 0}, {0, 1}, {0, 0}, {0, -1}};
int turn[4][2] = {{3, 1}, {0, 2}, {1, 3}, {2, 0}};
char res[2000][2000];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N && N)
    {
        memset(ts, 0, sizeof(ts));
        memset(res, ' ', sizeof(res));
        int L = 1 << N;
        for (int i = L; i > 1; i >>= 1)
        {
            for (int j = i >> 1, t = 0; j < L; j += i, t = !t)
                ts[j] = t;
        }
        int x1, x2, y1, y2;
        x1 = y1 = 1000;
        x2 = y2 = 1000;
        int x = 1000, y = 1001, d = 1;
        res[1000][1000] = '_';
        for (int i = 1; i < L; ++i)
        {
            d = turn[d][ts[i]];
            x += pre[d][0];
            y += pre[d][1];
            res[x][y] = draw[d];
            x1 = min(x1, x);
            x2 = max(x2, x);
            y1 = min(y1, y);
            y2 = max(y2, y);
            x += nxt[d][0];
            y += nxt[d][1];
        }
        for (int x = x1; x <= x2; ++x)
        {
            string line(res[x] + y1, res[x] + y2 + 1);
            while (!line.empty() && line.back() == ' ')
                line.pop_back();
            cout << line << endl;
        }
        cout << '^' << endl;
    }
    return 0;
}