#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <functional>
#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int N;
llong nums[300300];
llong l[300300];
llong r[300300];

int main()
{
    while (cin >> N)
    {
        FO (i, 3 * N)
            cin >> nums[i];
        priority_queue<llong, vector<llong>, greater<llong> > ql;
        llong lsum = 0, rsum = 0;
        FO (i, N)
        {
            ql.push(nums[i]);
            lsum += nums[i];
        }
        l[0] = lsum;
        FO (i, N)
        {
            lsum += nums[N + i];
            ql.push(nums[N + i]);
            lsum -= ql.top();
            ql.pop();
            l[i + 1] = lsum;
        }
        priority_queue<llong> qr;
        FO (i, N)
        {
            qr.push(nums[3 * N - 1 - i]);
            rsum += nums[3 * N - 1 - i];
        }
        r[N] = rsum;
        FO (i, N)
        {
            rsum += nums[2 * N - 1 - i];
            qr.push(nums[2 * N - 1 - i]);
            rsum -= qr.top();
            qr.pop();
            r[N - 1 - i] = rsum;
        }
        llong res = LLONG_MIN;
        FO (i, N + 1)
            res = max(res, l[i] - r[i]);
        cout << res << endl;
    }
    return 0;
}