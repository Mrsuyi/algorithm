#include <algorithm>
#include <array>
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
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0fffffff, MOD = 1e9 + 7, EPS = 1e-8;

inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

llong solve(int K, int A, int B)
{
    unordered_map<int, llong> cur;
    cur[A - 1] = -1;
    cur[B] = 1;
    for (int k = K - 1; k >= 0; --k)
    {
        int half = 1 << k;
        unordered_map<int, llong> nxt;
        for (const auto& p : cur)
        {
            if (p.first < half)
                nxt[p.first] += p.second;
            else
            {
                nxt[p.first - half] += p.second * 2;
                nxt[half - 1] += p.second;
            }
        }
        swap(cur, nxt);
    }
    return cur[0];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        int K, A, B;
        cin >> K >> A >> B;
        int tot = 1 << K;
        printf("Case %d: %lld\n", t + 1, solve(K, tot - B, tot - A));
    }
    return 0;
}