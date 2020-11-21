#include <cmath>
#include <vector>
using namespace std;

// Custom hash function for vector.
namespace std {
template <>
struct hash<vector<int>> {
  size_t operator()(const vector<int>& vec) const {
    size_t seed = 0;
    for (size_t v : vec) {
      seed ^= v + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};
}  // namespace std

// Euclidean algorithm. a >= b.
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

// Extended Euclidean algorithm. a >= b
// ax + by = k*gcd(a, b)
void exgcd(int a, int b, int& d, int& x, int& y, int k = 1) {
  if (b) {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  } else {
    d = a, x = k, y = 0;
  }
}

// Calculate prime numbers.
vector<int> brute_force(int n) {
  vector<int> primes;
  primes.reserve(n / 10 + 500);
  for (int i = 2; i <= n; ++i) {
    int j = 2, k = sqrt(i);
    while ((j <= k) && (i % j)) ++j;
    if (j > k) primes.push_back(i);
  }
  return primes;
}

vector<int> euler_filtering(int n) {
  vector<bool> not_prime(n + 1, false);
  vector<int> primes;
  primes.reserve(n / 10 + 500);
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) primes.push_back(i);
    for (size_t j = 0; j < primes.size(); ++j) {
      if (i * primes[j] > n) break;
      not_prime[i * primes[j]] = true;
      if (i % primes[j] == 0) break;
    }
  }
  return primes;
}

vector<int> eratosthenes_filtering(int n) {
  vector<bool> not_prime(n + 1, false);
  vector<int> primes;
  primes.reserve(n / 10 + 500);
  for (long long i = 2; i <= n; ++i) {
    if (not_prime[i]) continue;
    primes.push_back(i);
    for (long long j = i * i; j <= n; j += i) not_prime[j] = true;
  }
  return primes;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    int n = rand() % 100000;
    vector<int> a = brute_force(n);
    vector<int> b = euler_filtering(n);
    vector<int> c = eratosthenes_filtering(n);
    assert(a == b);
    assert(b == c);
    printf("Number of primes under %d: %zu\n", n, a.size());
  }
  return 0;
}
