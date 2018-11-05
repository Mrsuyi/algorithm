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
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) {
  return fabs(a - b) < EPS;
}

int main() {
  llong n, k;
  while (~scanf("%lld %lld", &n, &k)) {
    llong res = 0;
    for (llong i = 1; i <= n;) {
      llong p = k / i;
      if (p == 0) {
        res += k * (n - i + 1);
        break;
      }
      llong j = k / p;
      if (j > n)
        j = n;
      llong mi = k % i;
      llong mj = k % j;
      res += (mi + mj) * ((mi - mj) / p + 1) / 2;
      i = j + 1;
    }
    printf("%lld\n", res);
  }
  return 0;
}
