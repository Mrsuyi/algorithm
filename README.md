# Templates

## Bit
+ Get last "1" of n
```cpp
n = k & -k;
```

+ Remove last "1" from n
```cpp
n = k & (k - 1);
```

+ Traverse subsets of k (e.g. k=5 -> {101, 100, 001})
  ```cpp
  for (int i = k; i; i = (i - 1) & k) {}
  ```

+ Binary indexed tree (Fenwick tree)
  ```cpp
  const int N = 1 << 20;
  int arr[N] = {0};

void add(int i, int val) {
  while (i < N) {
    arr[i] += val;
    i += i & -i;
  }
}
int sum(int i) {
  int res = 0;
  while (i) {
    res += arr[i];
    i = i & (i - 1);
  }
  return res;
}
```

## Math

+ GCD (Greatest Common Divisor)
  ```cpp
  // a >= b > 0
  int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
  }

// Extended GCD: a*x+b*y=gcd(a, b)
void exgcd(int a, int b, int& d, int& x, int& y) {
  if (b) {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  } else {
    d = a, x = 1, y = 0;
  }
}
```

+ Prime numbers
```cpp
// Eratosthenes filtering
// O(NloglogN)
bool not_prime[100000] = {0};
int primes[100000];
int eratosthenes_filtering(int n) {
  int tot = 0;
  for (int i = 2; i <= n; ++i) {
    if (not_prime[i])
      continue;
    primes[tot++] = i;
    for (int j = i * i; j <= n; j += i)
      not_prime[j] = true;
  }
  return tot;
}

// Euler filtering
// O(N)
bool not_prime[100000] = {0};
int primes[100000];
int euler_filtering(int n) {
  int tot = 0;
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i])
      primes[tot++] = i;
    for (int j = 0; j < tot; ++j) {
      if (i * primes[j] > n)
        break;
      not_prime[i * primes[j]] = true;
      if (i % primes[j] == 0)
        break;
    }
  }
  return tot;
}

// Hash util
namespace std {
  template <> struct hash<vector<int>> {
    size_t operator()(const vector<int> &vec) const {
      size_t seed = 0;
      for (size_t v : vec) {
        seed ^= v + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
      return seed;
    }
  };
} // namespace std
```

