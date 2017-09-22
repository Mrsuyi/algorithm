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

vector<char> edges[256];
int N;
char i2c[10];
int c2i[256];
int pos[10];
string prefix, res;
int mink;

void dfs(int cur, int k)
{
    if (cur == N)
    {
        if (k < mink)
        {
            mink = k;
            res = prefix;
        }
        return;
    }
    for (int u = 0; u < N; ++u)
    {
        if (pos[u] != -1)
            continue;
        int cnt = 0;
        for (int i = 0; i < edges[u].size(); ++i)
        {
            int v = edges[u][i];
            if (pos[v] != -1)
                k = max(k, cur - pos[v]);
            else
                ++cnt;
        }
        if (cnt > mink || k > mink)
            return;
        pos[u] = cur;
        prefix.push_back(u);
        dfs(cur + 1, k);
        prefix.pop_back();
        pos[u] = -1;
    }
}

int main()
{
    string input;
    while (cin >> input)
    {
        if (input == "#")
            break;

        // clear
        N = 0;
        for (char c = 'A'; c <= 'Z'; ++c)
        {
            if (strchr(&input[0], c) != NULL)
            {
                c2i[c] = N;
                edges[N].clear();
                i2c[N++] = c;
            }
        }
        memset(pos, -1, sizeof(pos));
        mink = INT_MAX;
        prefix.clear();
        res.clear();

        // read
        int u = c2i[input[0]];
        for (int i = 2; i < input.size(); ++i)
        {
            if (input[i] == ';')
            {
                u = c2i[input[i + 1]];
                i += 3;
            }
            int v = c2i[input[i]];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        // search
        dfs(0, 0);

        // output
        for (int i = 0; i < res.size(); ++i)
            cout << i2c[res[i]] << " ";
        cout << "-> " << mink << endl;
    }
    return 0;
}