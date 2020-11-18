\#Templates

\#Bit + Get last "1" of n

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
