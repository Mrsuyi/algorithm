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

struct Node
{
    int val, cnt;
    int l, r;
    Node() : cnt(0), l(-1), r(-1) {}
} nodes[300];
int tot = 1;

void insert(int val, const string& path)
{
    int cur = 0, i = 0;
    for (; i < path.size(); ++i)
    {
        if (path[i] == 'L')
        {
            if (nodes[cur].l == -1)
            {
                nodes[tot] = Node();
                nodes[cur].l = tot++;
            }
            cur = nodes[cur].l;
        }
        else
        {
            if (nodes[cur].r == -1)
            {
                nodes[tot] = Node();
                nodes[cur].r = tot++;
            }
            cur = nodes[cur].r;
        }
    }
    ++nodes[cur].cnt;
    nodes[cur].val = val;
}

int main()
{
    string s;
    nodes[0] = Node();
    while (cin >> s)
    {
        if (s == "()")
        {
            vector<int> cur, res;
            bool ok = true;
            cur.push_back(0);
            while (!cur.empty())
            {
                vector<int> nxt;
                FO (i, cur.size())
                {
                    int n = cur[i];
                    if (nodes[n].cnt != 1)
                    {
                        ok = false;
                        goto end;
                    }
                    res.push_back(nodes[n].val);
                    if (nodes[n].l != -1)
                        nxt.push_back(nodes[n].l);
                    if (nodes[n].r != -1)
                        nxt.push_back(nodes[n].r);
                }
                swap(nxt, cur);
            }
            end:
            if (ok)
            {
                cout << res[0];
                FOR (i, 1, res.size())
                    cout << " " << res[i];
                cout << endl;
            }
            else
            {
                cout << "not complete" << endl;
            }
            tot = 1;
            nodes[0] = Node();
        }
        else
        {
            int val = stoi(s.substr(1, s.find(',') - 1));
            string path = s.substr(s.find(',') + 1);
            path.pop_back();
            insert(val, path);
        }
    }
    return 0;
}