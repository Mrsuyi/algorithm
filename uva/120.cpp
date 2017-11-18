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
typedef long long llong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9 + 7, EPS = 1e-8;

inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 35;
int N;
int in[MAXN], sorted[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    while (getline(cin, s))
    {
        printf("%s\n", s.data());
        stringstream ss(s);
        for (N = 0; ss >> in[N]; ++N);
        memcpy(sorted, in, sizeof(in));
        sort(sorted, sorted + N);
        for (int i = N - 1; i >= 0; --i)
        {
            int idx = find(in, in + N, sorted[i]) - in;
            if (idx == i)
                continue;
            reverse(in, in + idx + 1);
            reverse(in, in + i + 1);
            printf("%d %d ", N - idx, N - i);
        }
        printf("0\n");
    }
    return 0;
}