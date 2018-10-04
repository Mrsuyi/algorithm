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

const int MAXN = 1010, mod = 10056;
int N, dp[MAXN][MAXN] = {0};
int res[MAXN] = {0};

int main() {
  dp[0][0] = 1;
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = (j * (dp[i - 1][j - 1] + dp[i - 1][j])) % mod;
    }
  }
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= i; ++j) {
      res[i] = (res[i] + dp[i][j]) % mod;
    }
  }
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> N;
    printf("Case %d: %d\n", i + 1, res[N]);
  }
  return 0;
}
