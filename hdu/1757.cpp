#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int K, M;
llong a[10][10], b[10][10];

void mul(llong a[10][10], llong b[10][10])
{
    llong tmp[10][10] = {0};
    FO (i, 10) FO (j, 10) FO (k, 10)
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % M;
    memcpy(a, tmp, sizeof(tmp));
}

int main()
{
    while (cin >> K >> M)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        FO (i, 10)
            cin >> a[9 - i][9];
        FO (i, 9)
            a[i + 1][i] = 1;
        FO (i, 10)
            b[i][i] = 1;
        if (K < 10)
        {
            printf("%d\n", K);
        }
        else
        {
            K -= 9;
            for (int i = 0; (1LL << i) <= K; ++i)
            {
                if (K & (1LL << i))
                    mul(b, a);
                mul(a, a);
            }
            int res = 0;
            FO (i, 10)
                res += i * b[i][9];
            printf("%d\n", res % M);
        }
    }
    return 0;
}