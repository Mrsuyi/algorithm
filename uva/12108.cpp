#include <climits>
#include <cstring>
#include <cfloat>
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
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int N;
int a[12], b[12], c[12];

int main()
{
    int t = 0;
    while (cin >> N)
    {
        ++t;
        if (N == 0)
            break;
        int awake = 0;
        FO (i, N)
        {
            cin >> a[i] >> b[i] >> c[i];
            --c[i];
            if (c[i] < a[i])
                ++awake;
        }
        FO (i, 10000)
        {
            int nawake = 0;
            FO (i, N)
            {
                if (c[i] == a[i] - 1)
                {
                    if (awake < N - awake)
                    {
                        ++c[i];
                    }
                    else
                    {
                        c[i] = 0;
                        ++nawake;
                    }
                }
                else
                {
                    c[i] = (c[i] + 1) % (a[i] + b[i]);
                    if (c[i] < a[i])
                        ++nawake;
                }
            }
            awake = nawake;
            if (awake == N)
            {
                printf("Case %d: %d\n", t, i + 2);
                goto end;
            }
        }
        printf("Case %d: -1\n", t);
        end:;
    }
    return 0;
}
