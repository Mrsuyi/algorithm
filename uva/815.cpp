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

int main()
{
    int M, N, t = 0;
    while (cin >> M >> N)
    {
        if (M == 0 && N == 0)
            break;
        ++t;
        int hs[1000];
        FO (i, M * N)
            cin >> hs[i];
        sort(hs, hs + M * N);
        hs[M * N] = INT_MAX;
        double sum;
        cin >> sum;
        sum /= 100;
        int i = 1;
        for (; i <= M * N; ++i)
        {
            sum += hs[i - 1];
            if (sum / i <= hs[i])
                break;
        }
        printf("Region %d\nWater level is %.2lf meters.\n%.2lf percent of the region is under water.\n\n",
            t, sum / i, 100.0 * i / (M * N));
    }
    return 0;
}