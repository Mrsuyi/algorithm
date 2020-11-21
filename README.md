# Templates

# Bit

*   Get last "1" of n

```cpp
n = k & -k;
```

*   Remove last "1" from n

```cpp
n = k & (k - 1);
```

*   Traverse subsets of k(e.g.k = 5->{101, 100, 001})

```cpp
for (int i = k; i; i = (i - 1) & k) {}
```

*   Extended Euclidean algorithm.

```cpp
// ax + by = d
void exgcd(int a, int b, int& d, int& x, int& y) {
  if (b) {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  } else {
    d = a, x = 1, y = 0;
  }
}
```

*   Binary indexed tree(Fenwick tree)

```cpp
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
    int res = 0;
    while (true) {
      res += val[i];
      if (i == 0)
        break;
      i &= i - 1;
    }
    return res;
  }

  vector<int> val;
};
```

*   Custom std::hash function

```cpp
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
```

*   Euler filtering get prime numbers

```cpp
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
