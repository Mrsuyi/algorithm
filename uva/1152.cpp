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
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;

inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 4040;
int N;
int nums[4][MAXN];
int sum[2][MAXN * MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        if (t > 0)
            printf("\n");
        cin >> N;
        FO (i, N)
            scanf("%d %d %d %d", &nums[0][i], &nums[1][i], &nums[2][i], &nums[3][i]);
        FO (i, N) FO (j, N)
            sum[0][i * N + j] = nums[0][i] + nums[1][j];
        FO (i, N) FO (j, N)
            sum[1][i * N + j] = nums[2][i] + nums[3][j];
        int N2 = N * N;
        sort(sum[0], sum[0] + N2);
        sort(sum[1], sum[1] + N2);
        int res = 0;
        for (int i = 0, j = N2 - 1; i < N2 && j >= 0;)
        {
            int s = sum[0][i] + sum[1][j];
            if (s < 0)
                ++i;
            else if (s > 0)
                --j;
            else
            {
                int p = i + 1, q = j - 1;
                while (p < N2 && sum[0][p] == sum[0][i]) ++p;
                while (q >= 0 && sum[1][q] == sum[1][j]) --q;
                res += (p - i) * (j - q);
                i = p;
                j = q;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}