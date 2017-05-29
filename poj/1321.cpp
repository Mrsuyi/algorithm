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

int cnt1(int a)
{
    int res = 0;
    while (a)
    {
        ++res;
        a &= a - 1;
    }
    return res;
}

int N, K;
char matrix[10][10];

int main()
{
    while (cin >> N >> K)
    {
        if (N == -1 && K == -1)
            break;
        FO (i, N)
            cin >> matrix[i];
        int dp[256] = {0};
        dp[0] = 1;
        FO (i, N)
        {
            int tmp[256];
            memcpy(tmp, dp, sizeof(tmp));
            FO (j, 256)
            {
                FO (k, N)
                {
                    if (!(j & (1 << k)) && matrix[i][k] == '#')
                    {
                        tmp[j | (1 << k)] += dp[j];
                    }
                }
            }
            memcpy(dp, tmp, sizeof(tmp));
        }
        int res = 0;
        FO (j, 256)
            if (cnt1(j) == K)
                res += dp[j];
        cout << res << endl;
    }
    return 0;
}