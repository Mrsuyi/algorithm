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
#define fi first
#define se second
#define XY pair<int, int>
#define FOR(x, n) for (int x = 0; x < n; ++x)
#define RFOR(x, n) for (int x = n - 1; x >= 0; --x)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int record[1 << 16][3];
int q[10000000];
int l = 0, r = 0;

int main()
{
    memset(record, -1, sizeof(record));
    
    int init = 0;
    FOR(i, 4)
    {
        string s;
        cin >> s;
        FOR(j, 4) if (s[j] == '+') init |= 1 << (4 * i + j);
    }
    q[0] = init;
    for (int l = 0, r = 1; l < r; ++l)
    {
        FOR(i, 4) FOR(j, 4)
        {
            int rev = 0;
            FOR(k, 4) rev |= (1 << (4 * k + j)) | (1 << (4 * i + k));
            int nxt = q[l] ^ rev;
            if (nxt != init && record[nxt][0] == -1)
            {
                record[nxt][0] = q[l];
                record[nxt][1] = i;
                record[nxt][2] = j;
                q[r++] = nxt;
                if (nxt == 0)
                    goto end;
            }
        }
    }
end:
    int cur = 0;
    vector<pair<int, int> > moves;
    while (cur != init)
    {
        moves.push_back(pair<int, int>());
        moves.back().fi = record[cur][1];
        moves.back().se = record[cur][2];
        cur = record[cur][0];
    }
    cout << moves.size() << endl;
    RFOR(i, moves.size())
        cout << (moves[i].fi + 1) << " " << (moves[i].se + 1) << endl;

    return 0;
};