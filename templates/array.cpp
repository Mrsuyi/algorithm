#include <iostream>
#include <vector>

using namespace std;

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
