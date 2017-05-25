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
typedef pair<string, string> pss;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int H, W;

int main()
{
    while (cin >> H >> W)
    {
        int res = INT_MAX;
        res = min(res, H);
        res = min(res, W);
        if (H % 3 == 0)
            res = 0;
        if (W % 3 == 0)
            res = 0;
        FO (i, 3)
        {
            int h1 = H / 3 + i;
            int h23 = H - h1;
            FO (j, 2)
            {
                int w1 = W / 2 + j;
                int w2 = W - w1;

                int area[3];
                area[0] = h1 * W;
                area[1] = w1 * h23;
                area[2] = w2 * h23;
                sort(area, area + 3);

                res = min(res, area[2] - area[0]);
            }
        }
        FO (i, 3)
        {
            int w1 = W / 3 + i;
            int w23 = W - w1;
            FO (j, 2)
            {
                int h1 = H / 2 + j;
                int h2 = H - h1;

                int area[3];
                area[0] = w1 * H;
                area[1] = w23 * h1;
                area[2] = w23 * h2;
                sort(area, area + 3);

                res = min(res, area[2] - area[0]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}