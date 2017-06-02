#include <algorithm>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
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
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
typedef unsigned char byte;
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int T;

int main()
{
    cin >> T;
    FO (t, T)
    {
        string old, nue;
        cin >> old >> nue;
        map<string, string> mold, mnue;
        for (size_t i = 1; i < old.size() - 1;)
        {
            size_t colon = old.find(':', i);
            size_t comma = old.find(',', i);
            if (comma == string::npos)
                comma = old.size() - 1;
            string key = old.substr(i, colon - i);
            string val = old.substr(colon + 1, comma - colon - 1);
            mold[key] = val;
            i = comma + 1;
        }
        for (size_t i = 1; i < nue.size() - 1;)
        {
            size_t colon = nue.find(':', i);
            size_t comma = nue.find(',', i);
            if (comma == string::npos)
                comma = nue.size() - 1;
            string key = nue.substr(i, colon - i);
            string val = nue.substr(colon + 1, comma - colon - 1);
            mnue[key] = val;
            i = comma + 1;
        }
        vector<string> add, del, chg;
        for (auto& p : mold)
            if (!mnue.count(p.first))
                del.push_back(p.first);
        for (auto& p : mnue)
            if (!mold.count(p.first))
                add.push_back(p.first);
        for (auto& p : mnue)
            if (mold.count(p.first) && mold[p.first] != p.second)
                chg.push_back(p.first);
        if (add.size() == 0 && del.size() == 0 && chg.size() == 0)
            printf("No changes\n");
        else
        {
            if (add.size() > 0)
            {
                string res = "+";
                FO (i, add.size())
                    res += add[i] + ',';
                res.pop_back();
                cout << res << endl;
            }
            if (del.size() > 0)
            {
                string res = "-";
                FO (i, del.size())
                    res += del[i] + ',';
                res.pop_back();
                cout << res << endl;
            }
            if (chg.size() > 0)
            {
                string res = "*";
                FO (i, chg.size())
                    res += chg[i] + ',';
                res.pop_back();
                cout << res << endl;
            }
        }
        printf("\n");
    }
    return 0;
}