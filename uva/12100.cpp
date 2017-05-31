#include <algorithm>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
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

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int T, N, M;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        queue<int> que;
        map<int, int> cnt;
        FO (i, N)
        {
            int val;
            cin >> val;
            ++cnt[val];
            que.push(val);
        }
        for (int time = 0;;)
        {
            int val = que.front();
            que.pop();
            if ((--cnt.end())->first > val)
            {
                que.push(val);
                if (M == 0)
                    M = que.size() - 1;
                else
                    --M;
            }
            else
            {
                ++time;
                if (--cnt[val] == 0)
                    cnt.erase(val);
                if (M == 0)
                {
                    printf("%d\n", time);
                    break;
                }
                else
                    --M;
            }
        }
    }
    return 0;
}