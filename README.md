# Templates

```cpp
// Get last "1" of n
n = k & -k;

// Remove last "1" from n
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

// [0, ma)
struct FenwickTree {
  FenwickTree(int ma) : val(ma, 0) {}

  void add(int i) {
    if (i == 0) {
      ++val[0];
      return;
    }
    int ma = val.size();
    while (i < ma) {
      ++val[i];
      i += i & -i;
    }
  }

  int get(int i) {
    int res = val[0];
    while (i) {
      res += val[i];
      i &= i - 1;
    }
    return res;
  }

  vector<int> val;
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
