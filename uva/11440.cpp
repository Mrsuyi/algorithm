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

const int mod = 1e8 + 7;

bool not_prime[10001000] = {0};
int primes[1000000];
int euler_filter_prime(int n) {
  int tot = 0;
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) {
      primes[tot++] = i;
    }
    for (int j = 0; j < tot; ++j) {
      if (i * primes[j] > n)
        break;
      not_prime[i * primes[j]] = true;
      if (i % primes[j] == 0)
        break;
    }
  }
  return tot;
}

llong phifac[10001000];

int main() {
  euler_filter_prime(10000001);
  phifac[1] = 1;
  for (llong i = 2; i < 10000001; ++i) {
    phifac[i] = (phifac[i - 1] * (not_prime[i] ? i : (i - 1))) % mod;
  }
  int N, M;
  while (cin >> N >> M && N && M) {
    llong res = phifac[M];
    for (llong i = M + 1; i <= N; ++i) {
      res = res * i % mod;
    }
    printf("%lld\n", (res - 1 + mod) % mod);
  }
  return 0;
}
