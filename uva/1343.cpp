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
typedef array<int, 2> pii;
typedef array<double, 2> pdd;
typedef array<llong, 2> pll;
const int INF = 0x0f0f0f0f, MOD = 1e9+7, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }
inline int gcd(int a, int b) { if (a < b) return gcd(b, a); return b == 0 ? a : gcd(b, a % b); }

int nums[24];
int rotates[8][7] =
{
    {22, 20, 15, 11, 6, 2, 0},
    {23, 21, 17, 12, 8, 3, 1},
    {4, 5, 6, 7, 8, 9, 10},
    {13, 14, 15, 16, 17, 18, 19},
    {1, 3, 8, 12, 17, 21, 23},
    {0, 2, 6, 11, 15, 20, 22},
    {19, 18, 17, 16, 15, 14, 13},
    {10, 9, 8, 7, 6, 5, 4}
};
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};
int num;
string mov;

int mis()
{
    int cnt[4] = {0};
    for (int i = 0; i < 8; ++i)
        ++cnt[nums[center[i]]];
    int res = INT_MIN;
    for (int i = 1; i <= 3; ++i)
        if (cnt[i] > res)
        {
            res = cnt[i];
            num = i;
        }
    return 8 - res;
}

bool dfs(int d)
{
    int cnt = mis();
    if (cnt == 0)
        return true;
    if (cnt > d)
        return false;
    int rec[24];
    memcpy(rec, nums, sizeof(rec));
    for (int i = 0; i < 8; ++i)
    {
        int tmp = nums[rotates[i][6]];
        for (int j = 6; j > 0; --j)
            nums[rotates[i][j]] = nums[rotates[i][j - 1]];
        nums[rotates[i][0]] = tmp;
        mov.push_back('A' + i);
        if (dfs(d - 1))
            return true;
        mov.pop_back();
        memcpy(nums, rec, sizeof(rec));
    }
    return false;
}

int main()
{
    while (cin >> nums[0] && nums[0])
    {
        mov = "";
        for (int i = 1; i < 24; ++i)
            cin >> nums[i];
        for (int d = 0; ; ++d)
            if (dfs(d))
                break;
        if (mov.size() == 0)
        {
            cout << "No moves needed" << endl;
            cout << num << endl;
        }
        else
        {
            cout << mov << endl;
            cout << num << endl;
        }
    }
    return 0;
}