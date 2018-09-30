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

int T, K;
string r1[6], r2[6], c1[5], c2[5], overlap[5];
int combines[6];

int main() {
  scanf("%d", &T);
  while (T--) {
    cin >> K;
    --K;
    for (int i = 0; i < 6; ++i)
      cin >> r1[i];
    for (int i = 0; i < 6; ++i)
      cin >> r2[i];
    for (int i = 0; i < 5; ++i) {
      c1[i] = string(6, ' ');
      c2[i] = string(6, ' ');
    }
    for (int i = 0; i < 6; ++i)
      for (int j = 0; j < 5; ++j) {
        c1[j][i] = r1[i][j];
        c2[j][i] = r2[i][j];
      }
    for (int i = 0; i < 5; ++i) {
      overlap[i].clear();
      for (char c = 'A'; c <= 'Z'; ++c) {
        if (c1[i].find(c) != string::npos && c2[i].find(c) != string::npos)
          overlap[i].push_back(c);
      }
      sort(overlap[i].begin(), overlap[i].end());
    }
    memset(combines, 0, sizeof(combines));
    combines[5] = 1;
    for (int i = 4; i >= 0; --i)
      combines[i] = combines[i + 1] * overlap[i].size();
    if (combines[0] <= K) {
      printf("NO\n");
      continue;
    }
    string res;
    for (int i = 0; i < 5; ++i) {
      int cur = K / combines[i + 1];
      res.push_back(overlap[i][cur]);
      K -= cur * combines[i + 1];
    }
    cout << res << endl;
  }
  return 0;
}
