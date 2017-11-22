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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    while (cin >> N && N)
    {
        priority_queue<int, vector<int>, greater<int>> que;
        int num;
        FO (i, N)
        {
            cin >> num;
            que.push(num);
        }
        int res = 0;
        while (que.size() > 1)
        {
            int a = que.top();
            que.pop();
            int b = que.top();
            que.pop();
            res += a + b;
            que.push(a + b);
        }
        printf("%d\n", res);
    }
    return 0;
}