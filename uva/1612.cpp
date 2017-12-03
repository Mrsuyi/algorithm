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

const int MAXN = 20000;
int N;
int nums[MAXN][4], srt[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int o = 1; cin >> N && N; ++o)
    {
        for (int i = 1; i <= N; ++i)
        {
            double a, b, c;
            scanf("%lf %lf %lf", &a, &b, &c);
            nums[i][0] = round(a * 100);
            nums[i][1] = round(b * 100);
            nums[i][2] = round(c * 100);
        }
        FO (i, N)
            scanf("%d", &srt[i]);
        bool ok = true;
        int pre = nums[srt[0]][0] + nums[srt[0]][1] + nums[srt[0]][2];
        for (int i = 1; i < N && ok; ++i)
        {
            set<int> st;
            for (int j = 0; j < 8; ++j)
            {
                int sum = 0;
                if (j & 1) sum += nums[srt[i]][0];
                if (j & 2) sum += nums[srt[i]][1];
                if (j & 4) sum += nums[srt[i]][2];
                st.insert(sum);
            }
            double cur = -1;
            for (auto it = st.rbegin(); cur == -1 && it != st.rend(); ++it)
                if ((srt[i] > srt[i - 1] && *it == pre) || *it < pre)
                    cur = *it;
            if (cur == -1)
                ok = false;
            else
                pre = cur;
        }
        if (ok)
            printf("Case %d: %.2lf\n", o, pre / 100.0);
        else
            printf("Case %d: No solution\n", o);
    }
    return 0;
}