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

template <class T>
void read(T& res) {
  res = 0;
  char c = getchar();
  while (c < '0')
    c = getchar();
  while (c >= '0')
    res = 10 * res + c - '0', c = getchar();
}

int input[1000100];
int nxt0[1000100];
int pre_dup[1000100];
int res[1000100];

int get_nxt0(int i) {
  if (nxt0[i] == i || nxt0[i] == -1)
    return nxt0[i];
  return nxt0[i] = get_nxt0(nxt0[i]);
}

int main() {
  int Z;
  scanf("%d", &Z);
  for (int z = 0; z < Z; ++z) {
    int n, m;
    scanf("%d %d", &n, &m);
    int bytes = sizeof(int) * (m + 10);
    for (int i = 0; i < m; ++i) {
      read(input[i]);
    }
    memset(nxt0, -1, bytes);
    for (int i = m - 1; i >= 0; --i) {
      if (input[i] == 0) {
        nxt0[i] = i;
      } else {
        nxt0[i] = nxt0[i + 1];
      }
    }
    memset(res, 0, bytes);
    memset(pre_dup, -1, bytes);
    bool ok = true;
    for (int i = 0; i < m; ++i) {
      if (input[i] == 0)
        continue;
      int pd = pre_dup[input[i]];
      int n0 = get_nxt0(pd + 1);
      if (n0 > i || n0 == -1) {
        ok = false;
        break;
      }
      res[n0] = input[i];
      nxt0[n0] = get_nxt0(n0 + 1);
      pre_dup[input[i]] = i;
    }

    if (ok) {
      printf("YES\n");
      for (int i = 0; i < m; ++i) {
        if (input[i] != 0)
          continue;
        if (i)
          printf(" ");
        printf("%d", res[i]);
      }
      printf("\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
