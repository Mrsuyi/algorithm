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

int main()
{
    int N;
    string s;
    cin >> N >> s;
    int cl = 0, cr = 0;
    int dl = 0, dr = 0;
    size_t pivot = -1;
    FO (i, s.size())
    {
        if (s[i] == '(')
            ++cl;
        else
            ++cr;
        if (cr - cl > dl)
        {
            dl = cr - cl;
            pivot = i;
        }
    }
    string sub = s.substr(pivot + 1);
    FO (i, sub.size())
    {
        if (s[i] == '(');
    }
    string res = string(dl, '(') + s + string(dr, ')');
    cout << res << endl;
    return 0;
}