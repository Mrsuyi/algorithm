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
struct Trie
{
    int pos;
    int nxt[10];
    Trie()
    {
        pos = -1;
        memset(nxt, -1, sizeof(nxt));
    }
} tries[4000000];
int tot = 1;

void insert(int* pt, int len, int idx)
{
    int cur = 0;
    while (len--)
    {
        if (tries[cur].nxt[*pt] == -1)
        {
            tries[tot] = Trie();
            tries[cur].nxt[*pt] = tot++;
        }
        cur = tries[cur].nxt[*pt];
        if (tries[cur].pos == -1)
            tries[cur].pos = idx;
        --pt;
    }
}

int num[2][30000] = {0};
int len = 1;

int main()
{
    // build
    num[0][0] = 1;
    num[1][0] = 1;
    insert(&num[0][0], 1, 0);
    FOR (i, 2, 100000)
    {
        int ia = i & 1, ib = !ia;
        int off = max(0, len - 60);
        FOR (j, off, len)
        {
            num[ia][j] += num[ib][j];
            num[ia][j + 1] += num[ia][j] / 10;
            num[ia][j] %= 10;
        }
        if (num[ia][len] > 0)
            ++len;
        insert(&num[ia][len - 1], min(40, len), i);
    }

    // query
    cin >> T;
    FO (t, T)
    {
        string s;
        cin >> s;
        int cur = 0;
        FO (j, s.size())
        {
            if (tries[cur].nxt[s[j] - '0'] == -1)
            {
                printf("Case #%d: -1\n", t + 1);
                goto end;
            }
            cur = tries[cur].nxt[s[j] - '0'];
        }
        printf("Case #%d: %d\n", t + 1, tries[cur].pos);
        end:;
    }
    return 0;
}