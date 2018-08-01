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
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

int res[30000010] = {0};

int main()
{
    for (int c = 1; c <= 15000000; ++c) {
        for (int a = 2 * c; a <= 30000000; a += c) {
            int b = a - c;
            if (c == (a ^ b)) ++res[a];
        }
    }
    for (int i = 2; i <= 30000000; ++i) res[i] += res[i - 1];

    int O;
    cin >> O;
    FO(o, O)
    {
        int N;
        cin >> N;
        printf("Case %d: %d\n", o + 1, res[N]);
    }
    return 0;
}
