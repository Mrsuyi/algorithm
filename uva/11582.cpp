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
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

ullong a, b, n;
ullong rems[1010][7000];
ullong t[1010];

int main()
{
    for (int i = 1; i <= 1000; ++i)
    {
        rems[i][0] = 0;
        rems[i][1] = 1 % i;
        for (int j = 2;; ++j)
        {
            rems[i][j] = (rems[i][j - 1] + rems[i][j - 2]) % i;
            if (rems[i][j - 1] == rems[i][0] && rems[i][j] == rems[i][1])
            {
                t[i] = j - 1;
                break;
            }
        }
    }

    int O;
    cin >> O;
    FO(o, O)
    {
        cin >> a >> b >> n;
        ullong pos = 1, div = a % t[n];
        while (b)
        {
            if (b & 1) pos = (pos * div) % t[n];
            div = (div * div) % t[n];
            b >>= 1;
        }
        cout << rems[n][pos] << endl;
    }
    return 0;
}
