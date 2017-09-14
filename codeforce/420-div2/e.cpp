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

const int MOD = 1e9 + 7;
llong N, K, C;
llong stt[16], tran[16][16], sum[16][16];

void mul(llong a[16][16], llong b[16][16])
{
    llong tmp[16][16] = {0};
    FO (i, C) FO (j, C) FO (k, C)
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % MOD;
    memcpy(a, tmp, sizeof(tmp));
}

void calc(llong times)
{
    while (times)
    {
        if (times & 1)
            mul(sum, tran);
        mul(tran, tran);
        times >>= 1;
    }
}

int main()
{
    while (cin >> N >> K)
    {
        memset(stt, 0, sizeof(stt));
        stt[0] = 1;
        FO (t, N)
        {
            llong a, b, c;
            cin >> a >> b >> c;
            b = min(b, K);
            C = c + 1;
            for (llong j = c + 1; j < 16; ++j)
                stt[j] = 0;
            memset(tran, 0, sizeof(tran));
            memset(sum, 0, sizeof(sum));
            for (llong j = 0; j <= c; ++j)
            {
                sum[j][j] = 1;
                tran[j][j] = 1;
                if (j - 1 >= 0)
                    tran[j][j - 1] = 1;
                if (j + 1 <= c)
                    tran[j][j + 1] = 1;
            }
            calc(b - a);
            llong tmp[16] = {0};
            FO (i, C) FO (j, C)
                tmp[i] = (tmp[i] + stt[j] * sum[j][i]) % MOD;
            memcpy(stt, tmp, sizeof(tmp));
        }
        cout << stt[0] << endl;
    }
    return 0;
}