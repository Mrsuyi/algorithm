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
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0fffffff, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

// const int MAXN = 1100;
// int N;
// bool win[MAXN][MAXN];

// bool mul2(int num)
// {
//     return (num & (num - 1)) == 0;
// }

// bool cmp(const vector<int>& a, const vector<int>& b)
// {
//     return a.size() > b.size();
// }

// int main()
// {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     while (cin >> N)
//     {
//         FO (i, N)
//         {
//             string s;
//             cin >> s;
//             FO (j, N)
//                 win[i][j] = s[j] - '0';
//         }
//         unordered_set<int> yes, no;
//         for (int i = 1; i < N; ++i)
//             if (win[0][i])
//                 yes.insert(i);
//             else
//                 no.insert(i);
//         vector<vector<int>> groups;
//         for (auto ity = yes.begin(); ity != yes.end() && !no.empty();)
//         {
//             groups.push_back({*ity});
//             for (auto itn = no.begin(); itn != no.end();)
//             {
//                 if (win[*ity][*itn])
//                 {
//                     groups.back().push_back(*itn);
//                     itn = no.erase(itn);
//                 }
//                 else
//                     ++itn;
//             }
//             if (groups.back().size() == 1)
//             {
//                 groups.pop_back();
//                 ++ity;
//             }
//             else
//             {
//                 ity = yes.erase(ity);
//             }
//         }
//         for (auto& group : groups)
//         {
//             while (!mul2(group.size()) && !yes.empty())
//             {
//                 group.push_back(*yes.begin());
//                 yes.erase(yes.begin());
//             }
//         }
//         sort(groups.begin(), groups.end(), cmp);
//         vector<int> res;
//         for (const auto& group : groups)
//             for (int team : group)
//                 res.push_back(team);
//         for (int team : yes)
//             res.push_back(team);
//         res.push_back(0);
//         while (res.size() > 1)
//         {
//             vector<int> nxt;
//             for (int i = 0; i + 1 < res.size(); i += 2)
//             {
//                 printf("%d %d\n", res[i] + 1, res[i + 1] + 1);
//                 if (win[res[i]][res[i + 1]])
//                     nxt.push_back(res[i]);
//                 else
//                     nxt.push_back(res[i + 1]);
//             }
//             swap(nxt, res);
//         }
//     }
//     return 0;
// }

const int MAXN = 1100;
int N;
char win[MAXN][MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N)
    {
        FO (i, N)
            scanf("%s", win[i]);
        vector<int> yes, no;
        for (int i = 1; i < N; ++i)
            if (win[0][i] == '1')
                yes.push_back(i);
            else
                no.push_back(i);
        for (int k = N; k > 1; k >>= 1)
        {
            vector<int> yes2, no2, rst;
            for (int i = 0; i < yes.size(); ++i)
            {
                bool ok = false;
                for (int j = 0; !ok && j < no.size(); ++j)
                {
                    if (no[j] && win[yes[i]][no[j]] == '1')
                    {
                        printf("%d %d\n", yes[i] + 1, no[j] + 1);
                        no[j] = 0;
                        yes2.push_back(yes[i]);
                        ok = true;
                    }
                }
                if (!ok)
                    rst.push_back(yes[i]);
            }
            for (int i = 0; i < no.size(); ++i)
                if (no[i])
                    rst.push_back(no[i]);
            for (int i = 1; i < rst.size(); i += 2)
            {
                printf("%d %d\n", rst[i] + 1, rst[i + 1] + 1);
                if (win[rst[i]][rst[i + 1]] == '1')
                    swap(rst[i], rst[i + 1]);
                if (win[0][rst[i + 1]] == '1')
                    yes2.push_back(rst[i + 1]);
                else
                    no2.push_back(rst[i + 1]);
            }
            printf("1 %d\n", rst[0] + 1);
            swap(yes, yes2);
            swap(no, no2);
        }
    }
    return 0;
}