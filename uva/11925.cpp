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

const int MAXN = 330;
int N;
vector<int> res;
int que[3 * MAXN * MAXN + MAXN], l, r;

void do1()
{
    res.push_back(1);
    swap(que[l], que[l + 1]);
}
void do2()
{
    res.push_back(2);
    --l;
    que[l] = que[r];
    --r;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N && N)
    {
        res.clear();
        l = 3 * MAXN * MAXN;
        r = l + N - 1;
        FO (i, N)
            cin >> que[l + i];
        for (int i = 2; i <= N; ++i)
        {
            while (que[l] != i)
                do2();
            while (true)
            {
                do2();
                if (que[l] == i - 1)
                    break;
                do1();
            }
        }
        while (que[l] != 1)
            do2();
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i)
            cout << res[i];
        cout << endl;
    }
    return 0;
}