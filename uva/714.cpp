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
const int INF = 0x0fffffff, MOD = 1e9 + 7, EPS = 1e-8;

inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

const int MAXN = 550;
int N, K;
llong nums[MAXN];

bool ok(llong limit)
{
    int j = 0;
    for (int i = 0; i < K; ++i)
    {
        llong cnt = 0;
        while (cnt + nums[j] <= limit && N - j >= K - i)
            cnt += nums[j++];
        if (cnt == 0)
            return false;
    }
    return j == N;
}

void output(llong limit)
{
    vector<vector<llong>> res(K);
    int j = N - 1;
    for (int i = K - 1; i >= 0; --i)
    {
        llong cnt = 0;
        while (cnt + nums[j] <= limit && j >= i)
        {
            cnt += nums[j];
            res[i].push_back(nums[j]);
            --j;
        }
    }
    for (int i = 0; i < K; ++i)
    {
        if (i > 0)
            cout << " / ";
        reverse(res[i].begin(), res[i].end());
        for (int j = 0; j < res[i].size(); ++j)
        {
            if (j > 0)
                cout << " ";
            cout << res[i][j];
        }
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    FO (t, T)
    {
        cin >> N >> K;
        FO (i, N)
            cin >> nums[i];
        llong l = 0, r = LLONG_MAX;
        while (l < r)
        {
            llong mid = l + (r - l) / 2;
            if (ok(mid))
                r = mid;
            else
                l = mid + 1;
        }
        output(r);
    }
    return 0;
}