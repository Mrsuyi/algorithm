#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

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

vector<long> Invs(long n, long MOD) {
  vector<long> res(n + 1, 1);
  for (long i = 2; i <= n; ++i) {
    res[i] = (MOD - MOD / i) * res[MOD % i] % MOD;
  }
  return res;
}

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

int main() {
  vector<long> remainder = {2, 3, 2}, mods = {3, 5, 7};
  long val = CRT(remainder, mods);
  cout << val << endl;

  return 0;
}
