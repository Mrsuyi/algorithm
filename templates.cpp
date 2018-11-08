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
inline bool feq(const double& a, const double& b) {
  return fabs(a - b) < EPS;
}

// clang-format off
#define CAT_(x, y) x##y
#define CAT(x, y) CAT_(x, y)
#define BGN namespace CAT(splitter_, __LINE__) {
#define END };
// clang-format on

// a > b
// gcd of a/b
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

// a > b
// d = gcd(a, b), a * x + b * y = d
void exgcd(int a, int b, int& d, int& x, int& y) {
  if (b) {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  } else {
    d = a, x = 1, y = 0;
  }
}

// Eratosthenes filtering
// Get all prime numbers in [2, N].
// O(NloglogN)
BGN;
bool not_prime[10000] = {0};
void eratosthenes_filtering(int n) {
  int m = sqrt(n + 0.5);
  for (int i = 2; i <= m; ++i) {
    if (not_prime[i])
      continue;
    for (int j = i * i; j <= n; j += i)
      not_prime[j] = true;
  }
}
END;

// Euler filtering
// Get all prime numbers in [2, N].
// O(N)
BGN;
bool not_prime[10000] = {0};
int primes[10000];
int euler_filtering(int n) {
  int tot = 0;
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i])
      primes[tot++] = i;
    for (int j = 0; j < tot; ++j) {
      not_prime[i * primes[j]] = true;
      if (i % primes[j])
        break;
    }
  }
  return tot;
}
END;

// Unique prime-factorization theorem
// factorize a natural number into a mutiplication of prime numbers.
BGN;
int primes[10000];
int tot;
vector<pii> factorize(int n) {
  vector<pii> res;
  for (int i = 0; i < tot && primes[i] <= n && n > 1; ++i) {
    if (n % primes[i] == 0) {
      res.push_back({primes[i], 0});
      while (n % primes[i] == 0) {
        ++res.back().second;
        n /= primes[i];
      }
    }
  }
  if (n > 1)
    res.push_back({n, 1});
  return res;
}
END;

// Euler Phi function
// number of m in [1, N] that is coprime to N.
BGN;
int phi[10000] = {0};
void euler_phi() {
  phi[1] = 1;
  for (int i = 2; i < 10000; ++i) {
    if (phi[i])
      continue;
    for (int j = i; j < 10000; j += i) {
      if (!phi[j])
        phi[j] = j;
      phi[j] = phi[j] * (i - 1) / i;
    }
  }
}
END;

int main() {
  return 0;
}
