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

// const int MAXN = 1010;
// int N;
// vector<vector<int>> res;
// int bfs[MAXN], dfs[MAXN];

// int main()
// {
//     while (cin >> N)
//     {
//         res = vector<vector<int>>(N + 1);
//         FO (i, N)
//             cin >> bfs[i];
//         FO (i, N)
//             cin >> dfs[i];
//         int ibfs = 1;
//         vector<pair<int, int>> cur = {{dfs[0], 0}};
//         while (!cur.empty())
//         {
//             vector<pair<int, int>> nxt;
//             for (int i = 0; i < cur.size(); ++i)
//             {
//                 int key = cur[i].fi;
//                 int bgn = cur[i].se + 1;
//                 int end = (i < cur.size() - 1) ? cur[i + 1].se : N;
//                 for (int j = bgn; j < end; ++j)
//                 {
//                     if (ibfs < N && dfs[j] == bfs[ibfs])
//                     {
//                         ++ibfs;
//                         res[key].push_back(dfs[j]);
//                         nxt.push_back({dfs[j], j});
//                     }
//                 }
//             }
//             swap(cur, nxt);
//         }
//         for (int i = 1; i <= N; ++i)
//         {
//             sort(res[i].begin(), res[i].end());
//             cout << i << ":";
//             if (!res[i].empty())
//             {
//                 cout << res[i][0];
//                 for (int j = 1; j < res[i].size(); ++j)
//                     cout << " " << res[i][j];
//             }
//             cout << endl;
//         }
//     }
//     return 0;
// }

const int MAXN = 1010;
int N;
vector<int> stk;
vector<vector<int>> res;
int idx[MAXN];

int main()
{
    while (cin >> N)
    {
        int num;
        res = vector<vector<int>>(N + 1);
        FO (i, N)
        {
            cin >> num;
            idx[num] = (i == 0) ? -100 : i;
        }
        FO (i, N)
        {
            cin >> num;
            while (!stk.empty() && idx[stk.back()] >= idx[num] - 1)
                stk.pop_back();
            if (!stk.empty())
                res[stk.back()].push_back(num);
            stk.push_back(num);
        }
        for (int i = 1; i <= N; ++i)
        {
            cout << i << ":";
            for (int j = 0; j < res[i].size(); ++j)
                cout << " " << res[i][j];
            cout << endl;
        }
    }
    return 0;
}