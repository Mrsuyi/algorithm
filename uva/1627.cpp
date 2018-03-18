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
int colors[MAXN];
vector<int> edges[MAXN];
pair<vector<int>, vector<int>> dp[MAXN][MAXN], ept;

bool dfs(int u, vector<int>& a, vector<int>& b, int color)
{
    colors[u] = color;
    a.push_back(u);
    for (int i = 0; i < edges[u].size(); ++i)
    {
        int v = edges[u][i];
        if (colors[v] == -1)
        {
            if (!dfs(v, b, a, !color))
                return false;
        }
        else if (colors[v] == color)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        if (o)
            printf("\n");

        cin >> N;
        FO (i, N + 1)
            edges[i].clear();
        memset(colors, -1, sizeof(colors));
        FO (i, N + 1) FO (j, N + 1)
            dp[i][j] = {{}, {}};

        for (int i = 1; i <= N; ++i)
        {
            int u;
            bool conn[MAXN] = {0};
            while (cin >> u && u)
                conn[u] = true;
            for (int j = 1; j <= N; ++j)
                if (!conn[j] && j != i)
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
        }
        vector<pair<vector<int>, vector<int>>> cans;
        bool ok = true;
        for (int i = 1; i <= N; ++i)
        {
            if (colors[i] != -1)
                continue;
            vector<int> a, b;
            if (!dfs(i, a, b, 0))
            {
                ok = false;
                break;
            }
            cans.push_back({a, b});
        }
        if (!ok)
        {
            printf("No solution\n");
            continue;
        }
        // dp
        for (int i = 0; i < cans.size(); ++i)
        {
            for (int p = N; p >= 0; --p)
            {
                for (int q = N; q >= 0; --q)
                {
                    if (dp[p][q] != ept)
                        continue;
                    for (int k = 0; k < 2; ++k)
                    {
                        int m = p - cans[i].first.size();
                        int n = q - cans[i].second.size();
                        if (m >= 0 && n >= 0 && (m == 0 && n == 0 || dp[m][n] != ept))
                        {
                            dp[p][q] = dp[m][n];
                            dp[p][q].first.insert(dp[p][q].first.end(), cans[i].first.begin(), cans[i].first.end());
                            dp[p][q].second.insert(dp[p][q].second.end(), cans[i].second.begin(), cans[i].second.end());
                        }
                        swap(cans[i].first, cans[i].second);
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= N / 2; ++i)
        {
            if (dp[i][N - i] != ept)
                res = i;
        }
        // output
        cout << dp[res][N - res].first.size();
        for (int i = 0; i < dp[res][N - res].first.size(); ++i)
            cout << " " << dp[res][N - res].first[i];
        cout << endl;
        cout << dp[res][N - res].second.size();
        for (int i = 0; i < dp[res][N - res].second.size(); ++i)
            cout << " " << dp[res][N - res].second[i];
        cout << endl;
    }
    return 0;
}