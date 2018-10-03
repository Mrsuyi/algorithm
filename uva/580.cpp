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

int dp[50][4][2];

int main() {
  int n;
  while (cin >> n && n) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    for (int i = 1; i < n; ++i) {
      // append L
      dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][1][0] + dp[i - 1][2][0];
      dp[i][0][1] =
          dp[i - 1][0][1] + dp[i - 1][1][1] + dp[i - 1][2][1] + dp[i - 1][3][1];
      // append U
      dp[i][1][0] = dp[i - 1][0][0];
      dp[i][1][1] = dp[i - 1][0][1];
      dp[i][2][0] = dp[i - 1][1][0];
      dp[i][2][1] = dp[i - 1][1][1];

      dp[i][3][1] = dp[i - 1][2][0] + dp[i - 1][2][1] + dp[i - 1][3][1];
    }
    printf("%d\n", dp[n - 1][0][1] + dp[n - 1][1][1] + dp[n - 1][2][1] +
                       dp[n - 1][3][1]);
  }
  return 0;
}
