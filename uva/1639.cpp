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

const int MAXN = 400500;
ldouble ln[MAXN], sum[MAXN];

int main() {
  sum[0] = 0;
  for (int i = 1; i <= 400000; ++i) {
    ln[i] = log(i);
    sum[i] = sum[i - 1] + ln[i];
  }
  int n;
  ldouble p;
  for (int t = 0; cin >> n >> p; ++t) {
    ldouble res = 0;
    for (int i = 0; i <= n; ++i) {
      ldouble pa = (sum[2 * n - i] - sum[n] - sum[n - i]) + (n + 1) * log(p) +
                   (n - i) * log(1 - p);
      ldouble pb = (sum[2 * n - i] - sum[n] - sum[n - i]) +
                   (n + 1) * log(1 - p) + (n - i) * log(p);
      res += i * (exp(pa) + exp(pb));
    }
    printf("Case %d: %.6Lf\n", t + 1, res);
  }
  return 0;
}
