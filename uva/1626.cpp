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
#define fi first
#define se second
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7f7f7f7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 110;
int N;
string s;
string dp[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    getchar();
    unordered_map<char, string> match;
    match['('] = match[')'] = "()";
    match['['] = match[']'] = "[]";
    dp[0][0] = "";
    FO (o, O)
    {
        if (o)
            printf("\n");
        getchar();
        getline(cin, s);
        N = s.size();
        s = '^' + s;
        for (int i = 1; i <= N; ++i)
            dp[i][i] = match[s[i]];
        for (int l = 2; l <= N; ++l)
        {
            for (int i = 1, j = l; j <= N; ++i, ++j)
            {
                // AB
                int mik = i;
                for (int k = i + 1; k < j; ++k)
                    if (dp[i][k].size() + dp[k + 1][j].size() < dp[i][mik].size() + dp[mik + 1][j].size())
                        mik = k;
                dp[i][j] = dp[i][mik] + dp[mik + 1][j];

                // (A) or [B]
                if (s[i] == '(' && s[j] == ')' && dp[i + 1][j - 1].size() + 2 < dp[i][j].size())
                    dp[i][j] = '(' + dp[i + 1][j - 1] + ')';
                else if (s[i] == '[' && s[j] == ']' && dp[i + 1][j - 1].size() + 2 < dp[i][j].size())
                    dp[i][j] = '[' + dp[i + 1][j - 1] + ']';
            }
        }
        printf("%s\n", dp[1][N].data());
    }
    return 0;
}
