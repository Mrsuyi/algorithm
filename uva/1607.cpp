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

const int MAXM = 200200;
int N, M;
int output[MAXM], a[MAXM], b[MAXM];

int get(int n0)
{
    for (int i = 1; i <= M; ++i)
    {
        int l = (a[i] < 0) ? (-a[i] > n0) : output[a[i]];
        int r = (b[i] < 0) ? (-b[i] > n0) : output[b[i]];
        output[i] = !(l & r);
    }
    return output[M];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        cin >> N >> M;
        for (int i = 1; i <= M; ++i)
            cin >> a[i] >> b[i];
        int v0 = get(N);
        int v1 = get(0);
        if (v0 == v1)
            cout << string(N, '0') << endl;
        else
        {
            int l = 0, r = N;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (get(mid) == v0)
                    r = mid;
                else
                    l = mid + 1;
            }
            cout << string(r - 1, '0');
            cout << 'x';
            cout << string(N - r, '1');
            cout << endl;
        }
    }
    return 0;
}