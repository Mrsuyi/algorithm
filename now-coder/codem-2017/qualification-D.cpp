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

llong L, R;
llong cnt[10];

int head(int num)
{
    return to_string(num)[0] - '0';
}

void add(int bgn, int end)
{
    // [123, 456]   =>  [100, 400]
    // [6, 9]       =>  [6, 9]
    string sbgn = to_string(bgn);
    string send = to_string(end);
    string slo(1, sbgn[0]), shi(1, send[0]);
    slo.resize(sbgn.size(), '0');
    shi.resize(send.size(), '0');
    llong lo = stoi(slo), hi = stoi(shi);
    cnt[sbgn[0] - '0'] -= bgn - lo;
    cnt[send[0] - '0'] += end - hi + 1;
    while (slo.size() < shi.size() || (slo.size() == shi.size() && slo[0] < shi[0]))
    {
        cnt[slo[0] - '0'] += pow(10, slo.size() - 1);
        if (slo[0] == '9')
        {
            slo[0] = '1';
            slo.push_back('0');
        }
        else
        {
            ++slo[0];
        }
    }
}

int main()
{
    while (cin >> L >> R)
    {
        memset(cnt, 0, sizeof(cnt));
        llong i;
        for (i = 1; i * i <= R; ++i)
        {
            llong lo = max(i * i, L), hi = R;
            llong bgn = (lo - 1) / i, end = hi / i;
            if (end > bgn)
                cnt[head(i)] += end - bgn;
            bgn = max(bgn + 1, i + 1);
            if (end >= bgn)
                add(bgn, end);
        }
        for (int i = 1; i <= 9; ++i)
            cout << cnt[i] << endl;
    }
    return 0;
}