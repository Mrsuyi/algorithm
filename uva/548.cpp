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

int N, res, mi;
int in[10010], po[10010];

void dfs(int il, int ir, int pl, int pr, int sum)
{
    if (il > ir)
        return;
    int pivot = po[pr];
    int i = find(&in[il], &in[ir + 1], pivot) - in;
    int l1 = i - il;
    int l2 = ir - i;
    if (l1 == 0 && l2 == 0)
    {
        int s = sum + pivot;
        if (s < mi)
        {
            mi = s;
            res = pivot;
        }
        else if (s == mi)
            res = min(res, pivot);
    }
    else
    {
        dfs(il, i - 1, pl, pl + l1 - 1, sum + pivot);
        dfs(i + 1, ir, pl + l1, pr - 1, sum + pivot);
    }
}

int main()
{
    string sin, spo;
    while (getline(cin, sin))
    {
        mi = INT_MAX;
        getline(cin, spo);
        stringstream ssin(sin), sspo(spo);
        for (N = 0; ssin >> in[N] && sspo >> po[N]; ++N);
        dfs(0, N - 1, 0, N - 1, 0);
        cout << res << endl;
    }
    return 0;
}