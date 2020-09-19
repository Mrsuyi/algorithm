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
```


## String

+ KMP
```cpp
// KMP
// Returns index of first |target| in |str|, or -1 if not found.
int kmp(const string& str, const string& target) {
  // com[i] => length of longest common prefix&suffix in target[0, i].
  vector<int> com(target.size(), 0);
  for (int i = 1; i < target.size(); ++i) {
    com[i] = com[i - 1];
    while (com[i] > 0 && target[i] != target[com[i]]) {
      com[i] = com[com[i] - 1];
    }
    if (target[i] == target[com[i]]) {
      ++com[i];
    }
  }
  for (int i = 0, j = 0; i < str.size(); ++i) {
    while (j > 0 && str[i] != target[j]) {
      j = com[j - 1];
    }
    if (str[i] == target[j]) {
      ++j;
      if (j == target.size()) {
        return i - target.size() + 1;
      }
    }
  }
  return -1;
}
```

+ AC
```cpp
struct Trie {
  Trie(int len = 0) : len(len), fail(0), is_word(false) {}
  int len;
  int fail;
  bool is_word;
  unordered_map<char, int> children;
};

// Returns index of first |targets| in |str|, or -1 if not found.
int ac(const string& str, const vector<string>& targets) {
  // Build up tries.
  vector<Trie> tries(1);
  for (const string& target : targets) {
    int cur = 0;
    for (const char c : target) {
      if (tries[cur].children.count(c) == 0) {
        tries[cur].children[c] = tries.size();
        tries.push_back(Trie(tries[cur].len + 1));
      }
      cur = tries[cur].children[c];
    }
    tries[cur].is_word = true;
  }
  // Calculate fail for tries.
  deque<int> bfs = {0};
  while (!bfs.empty()) {
    int cur = bfs.front();
    bfs.pop_front();
    for (auto& kv : tries[cur].children) {
      char c = kv.first;
      int nxt = kv.second;
      bfs.push_back(nxt);
      if (cur == 0) {
        continue;
      }
      int match = tries[cur].fail;
      while (match != 0 && tries[match].children.count(c) == 0) {
        match = tries[match].fail;
      }
      if (tries[match].children.count(c)) {
        tries[nxt].fail = tries[match].children[c];
      } else {
        tries[nxt].fail = 0;
      }
    }
  }
  // Do match.
  int match = 0;
  for (int i = 0; i < str.size(); ++i) {
    char c = str[i];
    while (tries[match].fail != 0 && tries[match].children.count(c) == 0) {
      match = tries[match].fail;
    }
    if (tries[match].children.count(c)) {
      match = tries[match].children[c];
    }
    if (tries[match].is_word) {
      return i - tries[match].len + 1;
    }
  }
  return -1;
}

void debug_tries(const vector<Trie>& tries) {
  for (int i = 0; i < tries.size(); ++i) {
    printf("trie: %d len: %d fail: %d\n", i, tries[i].len, tries[i].fail);
    for (const auto& kv : tries[i].children) {
      printf("children: %c %d\n", kv.first, kv.second);
    }
  }
}
```
