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

const int MAXN = 100100;
int N;
int nums[MAXN], idxs[MAXN], movs[MAXN * 2], res;

void swp(int l, int r)
{
    movs[res++] = l;
    movs[res++] = r;
    int len = (r - l + 1) / 2;
    for (int i = 0; i < len; ++i)
    {
        swap(nums[l + i], nums[l + i + len]);
        swap(idxs[nums[l + i]], idxs[nums[l + i + len]]);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        cin >> N;
        res = 0;
        for (int i = 1; i <= N; ++i)
        {
            cin >> nums[i];
            idxs[nums[i]] = i;
        }
        for (int i = 1; i <= N; ++i)
        {
            if (idxs[i] == i)
                continue;
            if (idxs[i] + idxs[i] - i - 1 > N)
                swp(i + !((idxs[i] - i) & 1), idxs[i]);
            swp(i, idxs[i] + idxs[i] - i - 1);
        }
        printf("%d\n", res / 2);
        for (int i = 0; i < res; i += 2)
            printf("%d %d\n", movs[i], movs[i + 1]);
    }
    return 0;
}