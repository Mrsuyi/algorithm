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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) {
  return fabs(a - b) < EPS;
}

const llong MAXN = 50010;
llong phi[MAXN] = {0};
llong phi_sum[MAXN] = {0};

llong N;

void init() {
  phi[1] = 1;
  for (llong i = 2; i < MAXN; ++i) {
    if (phi[i])
      continue;
    for (llong j = i; j < MAXN; j += i) {
      if (!phi[j])
        phi[j] = j;
      phi[j] = phi[j] * (i - 1) / i;
    }
  }
  for (llong i = 1; i < MAXN; ++i)
    phi_sum[i] = phi_sum[i - 1] + phi[i];
}

int main() {
  init();
  while (~scanf("%lld", &N) && N) {
    printf("%lld\n", 2 * phi_sum[N] - 1);
  }
  return 0;
}
