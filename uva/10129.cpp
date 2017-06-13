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

int T, N;
int in[128], out[128];
int edge[128][128];
int root[128];

int getrt(int cur)
{
    if (root[cur] == cur)
        return cur;
    else
        return root[cur] = getrt(root[cur]);
}

bool conn()
{
    FO (i, 128)
        root[i] = i;
    FO (i, 128) FO (j, 128)
    {
        if (edge[i][j])
        {
            int ri = getrt(i);
            int rj = getrt(j);
            if (ri == rj)
                continue;
            root[ri] = root[rj] = root[i] = root[j] = i;
        }
    }
    unordered_set<int> st;
    FO (i, 128)
        if (in[i] != 0 || out[i] != 0)
            st.insert(getrt(i));
    return st.size() == 1;
}

int main()
{
    cin >> T;
    FO (t, T)
    {
        cin >> N;
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(edge, 0, sizeof(edge));
        FO (i, N)
        {
            string s;
            cin >> s;
            char head = s[0];
            char tail = s[s.size() - 1];
            ++in[head];
            ++out[tail];
            edge[head][tail] = edge[tail][head] = 1;
        }
        int in1out = 0, out1in = 0, el = 0;
        FO (i, 128)
        {
            if (in[i] == out[i])
                continue;
            else if (in[i] == out[i] + 1)
                ++in1out;
            else if (out[i] == in[i] + 1)
                ++out1in;
            else
                ++el;
        }
        bool res = (in1out == 1 && out1in == 1 || in1out == 0 && out1in == 0) && el == 0 && conn();
        cout << (res ? "Ordering is possible." : "The door cannot be opened.") << endl;
    }
    return 0;
}