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

int A, B, C, N;
char chrs[11] = {'*', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string input, res, nums;

int possible(int idx)
{
    if (idx == A + B)
    {
        int a = 0, b = 0;
        for (int i = 0; i < A; ++i)
            a = 10 * a + (nums[i] - '0');
        for (int i = A; i < A + B; ++i)
            b = 10 * b + (nums[i] - '0');
        string c = to_string(a * b);
        if (c.size() != C)
            return 0;
        for (int i = 0; i < C; ++i)
            if (nums[A + B + i] != '*' && nums[A + B + i] != c[i])
                return 0;
        return 1;
    }
    if (nums[idx] != '*')
        return possible(idx + 1);
    else
    {
        int cnt = 0;
        char c = ((idx == 0) || (idx == A) || (idx == A + B)) ? '1' : '0';
        for (; c <= '9'; ++c)
        {
            nums[idx] = c;
            cnt += possible(idx + 1);
            if (cnt > 1)
                return cnt;
        }
        nums[idx] = '*';
        return cnt;
    }
}

bool dfs(int idx, int chg)
{
    if (chg == 0)
    {
        nums = res;
        return possible(0) == 1;
    }
    for (int i = 0; i < 11; ++i)
    {
        if (i == 1 && ((idx == 0) || (idx == A) || (idx == A + B)))
            continue;

        if (chrs[i] == res[idx])
        {
            if (N - 1 - idx >= chg && dfs(idx + 1, chg))
                return true;
        }
        else
        {
            res[idx] = chrs[i];
            if (dfs(idx + 1, chg - 1))
                return true;
            res[idx] = input[idx];
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b, c;
    for (int t = 1; cin >> a >> b >> c && a != "0"; ++t)
    {
        A = a.size();
        B = b.size();
        C = c.size();
        N = A + B + C;
        input = a + b + c;
        for (int d = 0; ; ++d)
        {
            res = input;
            if (dfs(0, d))
            {
                a = res.substr(0, A);
                b = res.substr(A, B);
                c = res.substr(A + B, C);
                printf("Case %d: %s %s %s\n", t, a.data(), b.data(), c.data());
                break;
            }
        }
    }
    return 0;
}