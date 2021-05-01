#include <iostream>
#include <vector>

using namespace std;

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

int main() {
  for (int i = 0; i < 100; ++i) {
    int ma = rand() % 1000 + 1;
    printf("Test tree size: %d\n", ma);
    FenwickTree f(ma);
    vector<int> sum(ma, 0);
    for (int j = 0; j < 10000; ++j) {
      int v = rand() % ma;

      f.add(v);
      for (int k = v; k < ma; ++k) ++sum[k];

      for (int k = 0; k < ma; ++k) {
        assert(f.get(k) == sum[k]);
      }
    }
  }
  return 0;
}
