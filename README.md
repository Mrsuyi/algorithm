# Templates

```cpp
// Get last 1 of n
n = k & -k;

// Remove last 1 from n
n = k & (k - 1);

// Traverse subsets of k(e.g.k = 5->{101, 100, 001})
for (int i = k; i; i = (i - 1) & k) {}

// Count #1
int count1(int v) {
  v = v - ((v >> 1) & 0x55555555);
  v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
  v = (v & 0x0F0F0F0F) + ((v >> 4) & 0x0F0F0F0F);
  v = (v & 0x00FF00FF) + ((v >> 8) & 0x00FF00FF);
  v = (v & 0x0000FFFF) + ((v >> 16) & 0x0000FFFF);
  return v;
}

// Convert last 1 to decimal pos.
int last1pos(int i) {
  static const int MultiplyDeBruijnBitPosition[32] = {
    0,  1,  28, 2,  29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4,  8,
    31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6,  11, 5,  10, 9};
  return MultiplyDeBruijnBitPosition[((i & -i) * 0x077CB531U) >> 27];
}

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

// a/b % mod = m  ->  a*x % mod = m
//   a % mod = m*b % mod
//   a*x % mod = m*b*x % mod
//   m = m*b*x % mod
//   1 = b*x % mod
long rev(long b, long mod) {
  long d, x, y;
  exgcd(b, mod, d, x, y);
  return (x % mod + mod) % mod;
}

// mod >= 2
long rev2(long b, long mod) {
  long exp = mod - 2;
  long res = 1;
  long base = b;
  while (exp) {
    if (exp & 1) res = res * base % mod;
    base = base * base % mod;
    exp >>= 1;
  }
  return res;
}

vector<long> revs(long n, long MOD) {
  vector<long> res(n + 1, 1);
  for (long i = 2; i <= n; ++i) {
    res[i] = (MOD - MOD / i) * res[MOD % i] % MOD;
  }
  return res;
}

// [0, ma)
struct FenwickTree {
  FenwickTree(int ma) : cnt(ma, 0) {}

  void add(int i, int val = 1) {
    if (i == 0) {
      cnt[0] += val;
      return;
    }
    int ma = cnt.size();
    while (i < ma) {
      cnt[i] += val;
      i += i & -i;
    }
  }

  int get(int i) {
    int res = cnt[0];
    while (i) {
      res += cnt[i];
      i &= i - 1;
    }
    return res;
  }

  vector<int> cnt;
};

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

// Euler filtering get prime numbers
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
```
