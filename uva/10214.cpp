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

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int phi[2020] = {0};
void euler_phi(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (phi[i])
      continue;
    for (int j = i; j <= n; j += i) {
      if (!phi[j])
        phi[j] = j;
      phi[j] = phi[j] * (i - 1) / i;
    }
  }
}

int main() {
  euler_phi(2000);
  llong a, b;
  while (cin >> a >> b && a && b) {
    if (a > b)
      swap(a, b);
    llong k = 0;
    for (llong i = 1; i <= a; ++i) {
      k += phi[i] * (b / i);
      for (llong j = (b / i) * i + 1; j <= b; ++j) {
        if (gcd(i, j) == 1)
          ++k;
      }
    }
    double res = (4 * (k + 1.0)) / ((2 * a + 1) * (2 * b + 1) - 1);
    printf("%.7lf\n", res);
  }
  return 0;
}
