#include <vector>

using namespace std;

// Euler filtering get prime numbers
vector<long> euler_filtering(long n) {
  vector<bool> not_prime(n + 1, false);
  vector<long> primes;
  primes.reserve(n / 10 + 500);
  for (long i = 2; i <= n; ++i) {
    if (!not_prime[i]) primes.push_back(i);
    for (size_t j = 0; j < primes.size(); ++j) {
      if (i * primes[j] > n) break;
      not_prime[i * primes[j]] = true;
      if (i % primes[j] == 0) break;
    }
  }
  return primes;
}

// Extended Euclidean algorithm. a >= b
// ax + by = k*gcd(a, b)
void Exgcd(long a, long b, long& x, long& y, long k = 1) {
  if (b == 0) {
    x = k, y = 0;
  } else {
    Exgcd(b, a % b, y, x);
    y -= a / b * x;
  }
}

// Requires gcd(b, mod) == 1
long ModInv(long b, long MOD) {
  long d, x, y;
  Exgcd(b, MOD, x, y);
  return (x % MOD + MOD) % MOD;
}

// Requires mod to be a prime number.
long ModInvF(long b, long MOD) {
  long exp = MOD - 2;
  long res = 1;
  long base = b;
  while (exp) {
    if (exp & 1) res = res * base % MOD;
    base = base * base % MOD;
    exp >>= 1;
  }
  return res;
}

// Requires MOD > facs.size()
vector<long> facs, invs, facinvs;

void InitFacInv(long n, long MOD) {
  facs.resize(n + 1, 1);
  invs.resize(n + 1, 1);
  facinvs.resize(n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    facs[i] = facs[i - 1] * i % MOD;
    invs[i] = (MOD - MOD / i) * invs[MOD % i] % MOD;
    facinvs[i] = facinvs[i - 1] * invs[i] % MOD;
  }
}

long Cnm(long n, long m, long MOD) {
  if (n < m || n == m) return 0;
  return facs[n] * facinvs[n - m] * facinvs[m] % MOD;
}

// Get C(n, m) % p. Requires p to be a small number.
long Lucas(long n, long m, long MOD) {
  if (m == 0) return 1;
  return Cnm(n % MOD, m % MOD, MOD) * Lucas(n / MOD, m / MOD, MOD) % MOD;
}

// Chinese Remainder Theory
long CRT(const vector<long>& remainder, const vector<long>& mods) {
  long n = 1, ans = 0;
  for (long r : mods) n *= r;
  for (int i = 0; i < remainder.size(); ++i) {
    long m = n / mods[i], inv, y;
    Exgcd(m, mods[i], inv, y);  // inv * m mod r[i] = 1
    ans = (ans + remainder[i] * m * inv % n) % n;
  }
  return (ans % n + n) % n;
}

int main() { return 0; }
