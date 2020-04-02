#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

namespace eratosthenes {
// Eratosthenes filtering
// Get all prime numbers in [2, N].
// O(NloglogN)
bool not_prime[10000] = {0};
int eratosthenes_filtering(int n) {
  int m = sqrt(n + 0.5);
  for (int i = 2; i <= m; ++i) {
    if (not_prime[i])
      continue;
    for (int j = i * i; j <= n; j += i)
      not_prime[j] = true;
  }
  int res = 0;
  for (int i = 2; i <= n; ++i) {
    res += !not_prime[i];
  }
  return res;
}
}  // namespace eratosthenes

namespace euler {
// Euler filtering
// Get all prime numbers in [2, N].
// O(N)
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
        continue;
    }
  }
  return tot;
}
}  // namespace euler

// Unique prime-factorization theorem
// factorize a natural number into a mutiplication of prime numbers.
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

// Euler Phi function
// number of m in [1, N] that is coprime to N.
int phi[10000] = {0};
void euler_phi(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (phi[i]) {
      continue;
    }
    for (int j = i; j <= n; j += i) {
      if (!phi[j]) {
        phi[j] = j;
      }
      phi[j] = phi[j] * (i - 1) / i;
    }
  }
}

int main() {
  vector<int> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  assert(primes.size() == eratosthenes::eratosthenes_filtering(100));
  for (int prime : primes) {
    assert(!eratosthenes::not_prime[prime]);
  }

  assert(primes.size() == euler::euler_filtering(100));
  for (int prime : primes) {
    assert(!euler::not_prime[prime]);
  }

  return 0;
}
