#include <cmath>
#include <vector>
using namespace std;

namespace brute_force {

vector<int> brute_force(int n) {
  vector<int> primes;
  primes.reserve(n / 10 + 500);
  for (int i = 2; i <= n; ++i) {
    int j = 2, k = sqrt(i);
    while ((j <= k) && (i % j))
      ++j;
    if (j > k)
      primes.push_back(i);
  }
  return primes;
}

} // namespace brute_force

namespace euler {

vector<int> euler_filtering(int n) {
  vector<bool> not_prime(n + 1, false);
  vector<int> primes;
  primes.reserve(n / 10 + 500);
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i])
      primes.push_back(i);
    for (size_t j = 0; j < primes.size(); ++j) {
      if (i * primes[j] > n)
        break;
      not_prime[i * primes[j]] = true;
      if (i % primes[j] == 0)
        break;
    }
  }
  return primes;
}

} // namespace euler

namespace eratosthenes {

vector<int> eratosthenes_filtering(int n) {
  vector<bool> not_prime(n + 1, false);
  vector<int> primes;
  primes.reserve(n / 10 + 500);
  for (long long i = 2; i <= n; ++i) {
    if (not_prime[i])
      continue;
    primes.push_back(i);
    for (long long j = i * i; j <= n; j += i)
      not_prime[j] = true;
  }
  return primes;
}

} // namespace eratosthenes

int main() {
  for (int i = 0; i < 10; ++i) {
    int n = rand() % 100000;
    vector<int> a = brute_force::brute_force(n);
    vector<int> b = euler::euler_filtering(n);
    vector<int> c = eratosthenes::eratosthenes_filtering(n);
    assert(a == b);
    assert(b == c);
    printf("Number of primes under %d: %zu\n", n, a.size());
  }
  return 0;
}
