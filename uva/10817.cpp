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
#define fi first
#define se second
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7f7f7f7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

int S, M, N;
int dp[20000], fac[10] = {1, 3};

int get(int cur, int idx)
{
    return (cur % fac[idx + 1]) / fac[idx];
}
void add(int& cur, int idx)
{
    cur += fac[idx] * (get(cur, idx) != 2);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 2; i < 10; ++i)
        fac[i] = fac[i - 1] * 3;
    while (scanf("%d %d %d", &S, &M, &N) && S)
    {
        getchar();
        int stt = 0, cost = 0;
        FO (i, M)
        {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int a;
            ss >> a;
            cost += a;
            while (ss >> a)
                add(stt, a - 1);
        }
        memset(dp, INF, sizeof(dp));
        dp[stt] = cost;
        FO (i, N)
        {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int a, cost, subj[10] = {0};
            ss >> cost;
            while (ss >> a)
                subj[a - 1] = 1;
            for (int stt = fac[S] - 1; stt >= 0; --stt)
            {
                int tmp = stt;
                for (int j = 0; j < S; ++j)
                    if (subj[j])
                        add(tmp, j);
                dp[tmp] = min(dp[tmp], dp[stt] + cost);
            }
        }
        printf("%d\n", dp[fac[S] - 1]);
    }
    return 0;
}
