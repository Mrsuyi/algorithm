#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define fi first
#define se second
#define FOR(x, n) for (int x = 0; x < n; ++x)
#define RFOR(x, n) for (int x = n - 1; x >= 0; --x)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

bool record[1 << 16] = {0};
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool ok(int s)
{
    int mask = (1 << 16) - 1;
    return (mask & s == 0) || (mask & s == mask & -1);
}

int main()
{
    int init = 0;
    for (int i = 0; i < 4; ++i)
    {
        string s;
        cin >> s;
        FOR(j, 4) if (s[j] == 'b') init |= 1 << (4 * i + j);
    }
    if (ok(init))
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        vector<int> bfs;
        bfs.push_back(init);
        record[init] = true;
        for (int steps = 1; !bfs.empty(); ++steps)
        {
            vector<int> nxt;
            for (int i = 0; i < bfs.size(); ++i)
            {
                int status = bfs[i];
                for (int m = 0; m < 4; ++m)
                for (int n = 0; n < 4; ++n)
                {
                    int rev = 1 << (4 * m + n);
                    for (int k = 0; k < 4; ++k)
                    {
                        int x = m + dirs[k][0];
                        int y = n + dirs[k][1];
                        if (x >= 0 && x < 4 && y >= 0 && y < 4)
                            rev |= 1 << (4 * x + y);
                    }
                    int new_status = status ^ rev;
                    if (ok(new_status))
                    {
                        cout << steps << endl;
                        return 0;
                    }
                    if (!record[new_status])
                    {
                        record[new_status] = true;
                        nxt.push_back(new_status);
                    }
                }
            }
            swap(nxt, bfs);
        }
        cout << "Impossible" << endl;
    }
    
    return 0;
};