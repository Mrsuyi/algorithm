#include <algorithm>
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

int N, Q;
string s;
int dp[128][1600] = {0};

void build()
{
    for (char c = 'a'; c <= 'z'; ++c)
    {
        for (int i = 0; i < N; ++i)
        {
            int cnt = 0;
            for (int j = i; j < N; ++j)
            {
                if (s[j] != c)
                    ++cnt;
                dp[c][cnt] = max(dp[c][cnt], j - i + 1);
            }
        }
        for (int i = 1; i < 1600; ++i)
            dp[c][i] = max(dp[c][i], dp[c][i - 1]);
    }
}

int main()
{
    cin >> N;
    cin >> s;
    build();
    cin >> Q;
    FO (i, Q)
    {
        int m;
        char c;
        cin >> m >> c;
        cout << dp[c][m] << endl;
    }
    return 0;
}