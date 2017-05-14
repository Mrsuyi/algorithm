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

int I;
int a[2][2], b[2][2];

void mul(int a[2][2], int b[2][2])
{
    int tmp[2][2] = {0};
    FO (i, 2) FO (j, 2) FO (k, 2)
        tmp[i][j] = tmp[i][j] + a[i][k] * b[k][j];
    memcpy(a, tmp, sizeof(tmp));
}
void mul2(int a[2][2], int b[2][2])
{
    int tmp[2][2] = {0};
    FO (i, 2) FO (j, 2) FO (k, 2)
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % 10000;
    memcpy(a, tmp, sizeof(tmp));
}

int main()
{
    while (cin >> I)
    {
        memset(b, 0, sizeof(b));
        FO (i, 2) FO (j, 2)
        {
            a[i][j] = 1;
            b[i][i] = 1;
        }
        a[0][0] = 0;
        if (I <= 39)
        {
            for (; I; I >>= 1)
            {
                if (I & 1)
                    mul(b, a);
                mul(a, a);
            }
            printf("%d\n", b[1][0]);
        }
        else
        {
            double lg = - 0.5 * log10(5.0) + log10((1 + sqrt(5.0)) / 2.0) * I;
            lg -= (int)lg;
            for (; I; I >>= 1)
            {
                if (I & 1)
                    mul2(b, a);
                mul2(a, a);
            }
            printf("%d...%04d\n", (int)(pow(10.0, lg) * 1000), b[1][0]);
        }
    }
    return 0;
}