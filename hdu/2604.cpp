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

int L, M;
int a[4][4] = {0}, b[4][4] = {0};

void mul(int a[4][4], int b[4][4])
{
    int tmp[4][4] = {0};
    FO (i, 4) FO (j, 4) FO (k, 4)
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % M;
    memcpy(a, tmp, sizeof(tmp));
}

int main()
{
    while (cin >> L >> M)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        FO (i, 4)
            b[i][i] = 1;
        a[0][0] = a[0][1] = 1;
        a[1][2] = a[1][3] = 1;
        a[2][3] = 1;
        a[3][0] = 1;
        if (L == 0)
        {
            printf("0\n");
            continue;
        }
        for (; L; L >>= 1)
        {
            if (L & 1)
                mul(b, a);
            mul(a, a);
        }
        int res = 0;
        FO (i, 4)
            res += b[0][i];
        printf("%d\n", res % M);
    }
    return 0;
}