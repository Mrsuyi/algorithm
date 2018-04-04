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
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 18;
int N;
string inputs[MAXN];
int dp[1 << MAXN][MAXN][2], cover[MAXN][2][MAXN][2];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N && N)
    {
        FO (i, N)
            cin >> inputs[i];
        sort(inputs, inputs + N, [](const string& lhs, const string& rhs)
            { return lhs.size() > rhs.size(); });
        vector<string> strs[2];
        for (int i = 0; i < N; ++i)
        {
            bool unique = true;
            for (int j = 0; j < strs[0].size(); ++j)
            {
                string rev = inputs[i];
                reverse(rev.begin(), rev.end());
                if (strs[0][j].find(inputs[i]) != string::npos ||
                    strs[0][j].find(rev) != string::npos)
                {
                    unique = false;
                    break;
                }
            }
            if (unique)
                strs[0].push_back(inputs[i]);
        }
        N = strs[0].size();
        strs[1] = strs[0];
        for (string& s : strs[1])
            reverse(s.begin(), s.end());

        for (int i = 0; i < N; ++i)
        for (int di = 0; di < 2; ++di)
        for (int j = 0; j < N; ++j)
        for (int dj = 0; dj < 2; ++dj)
        {
            cover[i][di][j][dj] = 0;
            for (int k = max(1, int(strs[di][i].size() - strs[dj][j].size())); k < strs[di][i].size(); ++k)
            {
                if (equal(strs[di][i].begin() + k, strs[di][i].end(), strs[dj][j].begin()))
                {
                    cover[i][di][j][dj] = strs[di][i].size() - k;
                    break;
                }
            }
        }

        memset(dp, INF, sizeof(dp));
        dp[1][0][0] = strs[0][0].size();
        for (int i = 1; i < (1 << N); ++i)
        for (int j = 0; j < N; ++j)
        for (int dj = 0; dj < 2; ++dj)
        {
            if (dp[i][j][dj] == INF)
                continue;
            for (int k = 0; k < N; ++k)
            {
                if (i & (1 << k))
                    continue;
                for (int dk = 0; dk < 2; ++dk)
                    dp[i | (1 << k)][k][dk] = min(dp[i | (1 << k)][k][dk],
                        dp[i][j][dj] + int(strs[0][k].size()) - cover[j][dj][k][dk]);
            }
        }
        int res = INF;
        for (int i = 0; i < N; ++i)
            for (int d = 0; d < 2; ++d)
                res = min(res, dp[(1 << N) - 1][i][d] - cover[i][d][0][0]);
        res = max(res, 2);
        printf("%d\n", res);
    }
    return 0;
}