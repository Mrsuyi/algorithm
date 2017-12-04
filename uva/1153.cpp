#include <algorithm>
#include <array>
#include <cassert>
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
#define FO(x, n) for (int x = 0; x < n; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7fffff7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 1000100;
int N;
pll ods[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        if (o)
            printf("\n");
        cin >> N;
        priority_queue<llong> que;
        llong res = 0, cur = 0;
        FO (i, N)
            scanf("%lld %lld", &ods[i].second, &ods[i].first);
        sort(ods, ods + N);
        FO (i, N)
        {
            llong v = ods[i].second;
            llong t = ods[i].first;
            if (cur + v <= t)
            {
                ++res;
                que.push(v);
                cur += v;
            }
            else if (!que.empty() && v < que.top())
            {
                cur = cur - que.top() + v;
                que.pop();
                que.push(v);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}