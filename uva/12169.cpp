#include <algorithm>
#include <array>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
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
#ifdef __GNUC__
#if __cplusplus > 199711L
#include <unordered_map>
#include <unordered_set>
#else
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#endif
#else
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define FO(x, n) for (int x = 0; x < n; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

void gcd(llong a, llong b, llong& d, llong& x, llong& y)
{
    if (b) {
        gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    } else {
        x = 1;
        y = 0;
        d = a;
    }
}

llong a, b;
llong x[20010] = {0};

int main()
{
    llong O;
    cin >> O;
    for (llong i = 1; i < 2 * O; i += 2) scanf("%lld", &x[i]);
    for (llong a = 0; a <= 10000; ++a) {
        llong t, k, d;
        t = (x[3] - a * a * x[1]);
        gcd(10001, a + 1, d, k, b);
        if (t % d) continue;
        b = b * t / d;
        bool ok = true;
        for (llong i = 2; i <= 2 * O; ++i) {
            if (i & 1) {
                if ((a * x[i - 1] + b) % 10001 != x[i]) {
                    ok = false;
                    break;
                }
            } else {
                x[i] = (a * x[i - 1] + b) % 10001;
            }
        }
        if (ok) {
            for (llong i = 2; i <= 2 * O; i += 2) printf("%lld\n", x[i]);
            break;
        }
    }
    return 0;
}
