#include <algorithm>
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

int H, W;
const int MAXN = 220;
int hex2bin[128];
char hole2code[8];
bool matrix[MAXN][MAXN];
int hole[MAXN][MAXN], sym[MAXN][MAXN], chole, csym;
unordered_map<int, unordered_set<int>> sym2hole;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs_hole(int i, int j, int cur)
{
    hole[i][j] = cur;
    FO (k, 4)
    {
        int p = i + dirs[k][0];
        int q = j + dirs[k][1];
        if (p < 0 || p >= H || q < 0 || q >= 4 * W || matrix[p][q] || hole[p][q])
            continue;
        dfs_hole(p, q, cur);
    }
}

void dfs_symbol(int i, int j, int cur)
{
    sym[i][j] = cur;
    FO (k, 4)
    {
        int p = i + dirs[k][0];
        int q = j + dirs[k][1];
        if (p < 0 || p >= H || q < 0 || q >= 4 * W)
            continue;
        if (matrix[p][q])
        {
            if (!sym[p][q])
                dfs_symbol(p, q, cur);
        }
        else
        {
            sym2hole[cur].insert(hole[p][q]);
        }
    }
}

int main()
{
    for (char c = '0'; c <= '9'; ++c)
        hex2bin[c] = c - '0';
    hex2bin['a'] = 10;
    hex2bin['b'] = 11;
    hex2bin['c'] = 12;
    hex2bin['d'] = 13;
    hex2bin['e'] = 14;
    hex2bin['f'] = 15;
    //
    hole2code[0] = 'W';
    hole2code[1] = 'A';
    hole2code[2] = 'K';
    hole2code[3] = 'J';
    hole2code[4] = 'S';
    hole2code[5] = 'D';
    for (int t = 1; cin >> H >> W && H != 0; ++t)
    {
        FO (i, H)
        {
            string s;
            cin >> s;
            FO (j, W)
            {
                int val = hex2bin[s[j]];
                matrix[i][4 * j + 0] = val & (1 << 3);
                matrix[i][4 * j + 1] = val & (1 << 2);
                matrix[i][4 * j + 2] = val & (1 << 1);
                matrix[i][4 * j + 3] = val & (1 << 0);
            }
        }
        // hole
        memset(hole, 0, sizeof(hole));
        chole = 0;
        FO (i, H) FO (j, 4 * W)
        {
            if (matrix[i][j] || hole[i][j]) continue;
            dfs_hole(i, j, ++chole);
        }
        // symbol
        sym2hole.clear();
        memset(sym, 0, sizeof(sym));
        csym = 0;
        FO (i, H) FO (j, 4 * W)
        {
            if (!matrix[i][j] || sym[i][j]) continue;
            dfs_symbol(i, j, ++csym);
        }
        // cout << "hole: " << hole2sym.size() << " = " << chole << endl;
        // cout << "sym:  " << sym2hole.size() << " = " << csym << endl;
        // background
        unordered_set<int> back;
        FO (i, H)
        {
            if (!matrix[i][0])
                back.insert(hole[i][0]);
            if (!matrix[i][4 * W - 1])
                back.insert(hole[i][4 * W - 1]);
        }
        FO (j, 4 * W)
        {
            if (!matrix[0][j])
                back.insert(hole[0][j]);
            if (!matrix[H - 1][j])
                back.insert(hole[H - 1][j]);
        }
        for (int b : back)
            for (auto& p2 : sym2hole)
                p2.second.erase(b);
        //
        string res;
        for (auto& p : sym2hole)
            res.push_back(hole2code[p.second.size()]);
        sort(res.begin(), res.end());
        printf("Case %d: %s\n", t, res.data());
    }
    return 0;
}