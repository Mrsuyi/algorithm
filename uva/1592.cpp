#include <climits>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
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

int N, M;
string db[10010][12];

int main()
{
    while (cin >> N >> M)
    {
        getchar();
        FO (i, N)
        {
            string s;
            getline(cin, s);
            s.push_back(',');
            for (int l = 0, r = 0, j = 0; r < s.size(); ++r)
            {
                if (s[r] == ',')
                {
                    db[i][j] = s.substr(l, r - l);
                    l = r + 1;
                    ++j;
                }
            }
        }
        FO (i, M)
        FOR (j, i + 1, M)
        {
            unordered_map<string, unordered_map<string, int>> mp;
            FO (k, N)
            {
                if (mp[db[k][i]].count(db[k][j]))
                {
                    printf("NO\n%d %d\n%d %d\n", mp[db[k][i]][db[k][j]] + 1, k + 1, i + 1, j + 1);
                    goto end;
                }
                mp[db[k][i]][db[k][j]] = k;
            }
        }
        printf("YES\n");
        end:;
    }
    return 0;
}