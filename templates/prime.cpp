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
void eratosthenes_filtering(int n) {
  int m = sqrt(n + 0.5);
  for (int i = 2; i <= m; ++i) {
    if (not_prime[i])
      continue;
    for (int j = i * i; j <= n; j += i)
      not_prime[j] = true;
  }
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
        break;
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
  return 0;
}
