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

string s;

int main() {
  while (cin >> s) {
    int c0 = 0, c1 = 0, r0 = 0, r1 = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        ++c0;
        int nxt = (i + 1) % s.size();
        if (s[nxt] == '0')
          ++r0;
        else
          ++r1;
      } else
        ++c1;
    }
    double p1 = double(c1) / c0, p2 = double(r1) / r0;
    if (feq(p1, p2))
      cout << "EQUAL" << endl;
    else if (p1 < p2)
      cout << "ROTATE" << endl;
    else
      cout << "SHOOT" << endl;
  }
  return 0;
}
