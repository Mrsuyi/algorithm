#include <algorithm>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
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
# ifdef __GNUC__
# if __cplusplus > 199711L
# include <unordered_set>
# include <unordered_map>
# else
# include <tr1/unordered_map>
# include <tr1/unordered_set>
using namespace tr1;
# endif
# else
# include <unordered_map>
# include <unordered_set>
# endif
using namespace std;

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int l, r, mid, cnt[10000];

bool get(int off)
{
    int num;
    cin >> num;
    if (num == -1)
        return false;
    l = min(l, off);
    r = max(r, off);
    cnt[off] += num;
    get(off - 1);
    get(off + 1);
    return true;
}

int main()
{
    for (int t = 0; ; ++t)
    {
        l = r = mid = 5000;
        memset(cnt, 0, sizeof(cnt));
        if (!get(5000))
            return 0;
        printf("Case %d:\n", t + 1);
        cout << cnt[l];
        FOR (i, l + 1, r + 1)
            cout << " " << cnt[i];
        cout << endl << endl;
    }
    return 0;
}