#include <climits>
#include <cstring>
#include <cfloat>
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
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

int N, M;
bool conn[10][10][2];
int res[10];
const int H = 0, V = 1;
bool init = true;
int t = 0;

int main()
{
    while (cin >> N >> M)
    {
        ++t;
        memset(conn, 0, sizeof(conn));
        memset(res, 0, sizeof(res));
        FO (i, M)
        {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'H')
                conn[a - 1][b - 1][H] = true;
            else
                conn[b - 1][a - 1][V] = true;
        }

        FO (i, N - 1)
        FO (j, N - 1)
        FOR (l, 1, min(N - i, N - j))
        {
            bool ok = true;
            FO (k, l)
            {
                if (!conn[i + k][j][V] ||
                    !conn[i][j + k][H] ||
                    !conn[i + k][j + l][V] ||
                    !conn[i + l][j + k][H])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ++res[l];
        }
        bool has = false;
        FO (i, N)
            if (res[i])
            {
                has = true;
                break;
            }

        if (init)
            init = false;   
        else
            printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", t);

        if (has)
        {
            FO (i, N)
                if (res[i])
                    printf("%d square (s) of size %d\n", res[i], i);
        }
        else
        {
            printf("No completed squares can be found.\n");
        }
    }
    return 0;
}