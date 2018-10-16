#include <algorithm>
#include <array>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GNUC__
#if __cplusplus > 199711L
#include <unordered_map>
#include <unordered_set>
#else
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#endif
#else
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define FO(x, n) for (int x = 0; x < n; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef long double ldouble;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) {
  return fabs(a - b) < EPS;
}

int cnta[11], cntb[11];
int a, b;

void calc(int num, int* cnt) {
  memset(cnt, 0, sizeof(int) * 10);
  int r = 0;
  for (int base = 1; base <= num; base *= 10) {
    int l = num / (10 * base);
    int cur = (num / base) % 10;
    for (int i = 10; i >= 0; --i) {
      if (i == 0)
        --l;
      if (i < cur) {
        cnt[i] += (l + 1) * base;
      } else if (i == cur) {
        cnt[i] += l * base + r + 1;
      } else {
        cnt[i] += l * base;
      }
    }
    r += cur * base;
  }
}

int main() {
  while (cin >> a >> b && a && b) {
    if (a > b)
      swap(a, b);
    calc(--a, cnta);
    calc(b, cntb);
    cout << cntb[0] - cnta[0];
    for (int i = 1; i < 10; ++i)
      cout << " " << cntb[i] - cnta[i];
    cout << endl;
  }
  return 0;
}
