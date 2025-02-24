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
```
