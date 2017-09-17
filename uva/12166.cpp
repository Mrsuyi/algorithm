#include <algorithm>
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

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

int main()
{
    int T;
    cin >> T;
    FO (t, T)
    {
        string s;
        cin >> s;
        unordered_map<llong, llong> cnt;
        llong level = 0, total = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '[')
            {
                ++level;
            }
            else if (s[i] == ']')
            {
                --level;
            }
            else if (isdigit(s[i]))
            {
                llong num = s[i] - '0';
                while (i + 1 < s.size() && isdigit(s[i + 1]))
                {
                    num = 10LL * num + s[i + 1] - '0';
                    ++i;
                }
                ++cnt[num << level];
                ++total;
            }
        }
        llong ma = INT_MIN;
        for (auto& p : cnt)
        {
            ma = max(ma, p.second);
        }
        cout << (total - ma) << endl;
    }
    return 0;
}