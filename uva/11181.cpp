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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) {
  return fabs(a - b) < EPS;
}

int cnt1(int num) {
  int res = 0;
  while (num) {
    ++res;
    num &= num - 1;
  }
  return res;
}

int N, r;
double input[26], res[25];

int main() {
  int t = 0;
  while (cin >> N >> r && (N || r)) {
    printf("Case %d:\n", ++t);
    for (int i = 0; i < N; ++i)
      cin >> input[i];
    memset(res, 0, sizeof(res));
    int ma = 1 << N;
    double tot = 0;
    for (int i = 0; i < ma; ++i) {
      if (cnt1(i) == r) {
        double prob = 1;
        for (int j = 0; j < N; ++j) {
          if (i & (1 << j)) {
            prob *= input[j];
          } else {
            prob *= (1 - input[j]);
          }
        }
        for (int j = 0; j < N; ++j) {
          if (i & (1 << j))
            res[j] += prob;
        }
        tot += prob;
      }
    }
    for (int i = 0; i < N; ++i) {
      printf("%.6lf\n", res[i] / tot);
    }
  }
  return 0;
}
