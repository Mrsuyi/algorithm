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

llong dp[25][25][25] = {0};

int main() {
  dp[1][1][1] = 1;
  for (llong n = 2; n <= 20; ++n) {
    for (llong i = 1; i <= n; ++i) {
      for (llong j = 1; j <= n; ++j) {
        dp[n][i][j] = dp[n - 1][i - 1][j] + dp[n - 1][i][j - 1] +
                      dp[n - 1][i][j] * (n - 2);
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int N;
    int n, l, r;
    cin >> n >> l >> r;
    printf("%lld\n", dp[n][l][r]);
  }
  return 0;
};
