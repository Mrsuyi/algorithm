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
#ifdef __GNUC__
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
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
typedef long long llong;
typedef array<int, 2> pii;
typedef array<double, 2> pdd;
typedef array<llong, 2> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9+7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

int T, S;
double R, nums[8], w[1 << 6];
vector<pdd> stas[1 << 6];

void dfs(int s)
{
    if (stas[s].size())
        return;
    if (!(s & (s - 1)))
    {
        stas[s] = {{0, 0}};
        return;
    }
    for (int i = (s - 1) & s; i; i = (i - 1) & s)
    {
        int j = i ^ s;
        dfs(i);
        dfs(j);
        double o1 = w[j] / (w[i] + w[j]);
        double o2 = w[i] / (w[i] + w[j]);
        for (const pdd& d1 : stas[i])
        for (const pdd& d2 : stas[j])
        {
            double l = max(o1 + d1[0], -o2 + d2[0]);
            double r = max(-o1 + d1[1], o2 + d2[1]);
            if (l + r < R)
                stas[s].push_back({l, r});
        }
    }
}

int main()
{
    cin >> T;
    FO (t, T)
    {
        cin >> R >> S;
        vector<int> nums;
        FO (s, S)
        {
            nums.push_back(0);
            cin >> nums.back();
        }
        int all = (1 << S) - 1;
        for (int i = 0; i <= all; ++i)
            stas[i].clear();
        // calc weight sum
        memset(w, 0, sizeof(w));
        for (int i = 0; i < S; ++i)
        {
            int mask = (1 << i) - 1;
            for (int j = 1 << i; j < (1 << (i + 1)); ++j)
                w[j] = w[j & mask] + nums[i];
        }
        dfs(all);
        double res = -1;
        for (const pdd& d : stas[all])
            res = max(res, d[0] + d[1]);
        printf("%.15lf\n", res);
    }
    return 0;
}