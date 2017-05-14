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

int N;
int a[2][2], b[2][2];

void mul(int a[2][2], int b[2][2])
{
    int tmp[2][2] = {0};
    FO (i, 2) FO (j, 2) FO (k, 2)
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % 1024;
    memcpy(a, tmp, sizeof(tmp));
}

int main()
{
    int T;
    cin >> T;
    FO (t, T)
    {
        cin >> N;
        memset(b, 0, sizeof(b));
        b[0][0] = b[1][1] = 1;
        a[0][0] = 5;
        a[0][1] = 2;
        a[1][0] = 12;
        a[1][1] = 5;
        --N;
        for (; N; N >>= 1)
        {
            if (N & 1)
                mul(b, a);
            mul(a, a);
        }
        int res = 5 * b[0][0] + 2 * b[1][0];
        printf("%d\n", (2 * res - 1) % 1024);
    }
    return 0;
}