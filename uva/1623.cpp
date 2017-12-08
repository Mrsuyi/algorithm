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
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x7fffff7f, MOD = 1e9 + 7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

template <class T>
void read(T& res)
{
    res = 0;
    char c = getchar();
    while (c < '0') c = getchar();
    while (c >= '0') res = 10 * res + c - '0', c = getchar();
}

// const int MAXN = 1000100;
// int N, M;
// int full[MAXN], days[MAXN];
// queue<int> ques[MAXN];

// int main()
// {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     int O;
//     cin >> O;
//     FO (o, O)
//     {
//         cin >> N >> M;
//         for (int i = 0; i < M; ++i)
//             read(days[i]);
//         for (int i = 1; i <= N; ++i)
//             ques[i] = queue<int>();
//         for (int i = 0; i < M; ++i)
//             if (days[i])
//                 ques[days[i]].push(i);
//         map<int, int> can;
//         for (int i = 1; i <= N; ++i)
//             if (!ques[i].empty())
//             {
//                 can[ques[i].front()] = i;
//                 ques[i].pop();
//             }
//         bool res = true;
//         vector<int> sucks;
//         sucks.reserve(M);
//         for (int i = 0; i < M; ++i)
//         {
//             if (days[i])
//             {
//                 if (full[days[i]])
//                 {
//                     res = false;
//                     break;
//                 }
//                 else
//                 {
//                     full[days[i]] = 1;
//                     if (!ques[days[i]].empty())
//                     {
//                         can[ques[days[i]].front()] = days[i];
//                         ques[days[i]].pop();
//                     }
//                 }
//             }
//             else
//             {
//                 if (!can.empty())
//                 {
//                     full[can.begin()->second] = 0;
//                     sucks.push_back(can.begin()->second);
//                     can.erase(can.begin());
//                 }
//                 else
//                 {
//                     sucks.push_back(0);
//                 }
//             }
//         }
//         if (res)
//         {
//             printf("YES\n");
//             for (int i = 0; i < sucks.size(); ++i)
//             {
//                 if (i) printf(" ");
//                 printf("%d", sucks[i]);
//             }
//             printf("\n");
//         }
//         else
//             printf("NO\n");
//     }
//     return 0;
// }


// const int MAXN = 1000100;
// int N, M;
// int days[MAXN], lst[MAXN];

// int main()
// {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     int O;
//     cin >> O;
//     FO (o, O)
//     {
//         cin >> N >> M;
//         map<int, int> st;
//         for (int i = 0; i < M; ++i)
//         {
//             read(days[i]);
//             if (!days[i])
//                 st[i] = st.size();
//         }
//         memset(lst, -1, sizeof(lst));
//         bool res = true;
//         vector<int> sucks(st.size(), 0);
//         for (int i = 0; i < M; ++i)
//         {
//             if (!days[i])
//                 continue;
//             auto it = st.upper_bound(lst[days[i]]);
//             if (it == st.end() || it->first > i)
//             {
//                 res = false;
//                 break;
//             }
//             sucks[it->second] = days[i];
//             st.erase(it);
//             lst[days[i]] = i;
//         }
//         if (res)
//         {
//             printf("YES\n");
//             for (int i = 0; i < sucks.size(); ++i)
//             {
//                 if (i) printf(" ");
//                 printf("%d", sucks[i]);
//             }
//             printf("\n");
//         }
//         else
//             printf("NO\n");
//     }
//     return 0;
// }


const int MAXN = 1000100;
int N, M;
int f[MAXN], a[MAXN], ans[MAXN], lake[MAXN];

int find(int x)
{
    return (f[x] == x) ? f[x] : f[x] = find(f[x]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int O;
    cin >> O;
    FO (o, O)
    {
        cin >> N >> M;
        map<int, int> st;
        for (int i = 1; i <= M; ++i)
        {
            ans[i] = 0;
            read(a[i]);
        }
        int lst = M + 1;
        f[lst] = lst;
        for (int i = M; i >= 1; --i)
        {
            if (!a[i])
                lst = i;
            f[i] = lst;
        }
        f[0] = lst;
        bool res = true;
        for (int i = 1; i <= N; ++i)
            lake[i] = 0;
        for (int i = 1; i <= M; ++i)
        {
            if (!a[i])
                continue;
            int x = find(lake[a[i]]);
            if (x <= i)
                ans[x] = a[i], f[x] = find(x + 1);
            else
            {
                res = false;
                break;
            }
            lake[a[i]] = i;
        }
        if (res)
        {
            printf("YES\n");
            for (int i = 1; i <= M; ++i)
                if (!a[i])
                    printf("%d ", ans[i]);
            printf("\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
