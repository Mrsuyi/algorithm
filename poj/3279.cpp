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

int M, N;
int mincnt;
string res;
int matrix[18][16];
int dirs[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
    while (cin >> M >> N)
    {
        // reset
        mincnt = INT_MAX;
        res = "";
        memset(matrix, 0, sizeof(matrix));
        // input
        FO (i, M) FO (j, N)
            cin >> matrix[i + 1][j];
        // search
        FO (i, 1 << N)
        {
            int cnt = 0;
            int mat[18][16];
            int act[18][16] = {0};
            memcpy(mat, matrix, sizeof(mat));
            FO (j, N)
                if (i & (1 << j))
                    mat[0][j] = 1;
            FOR (j, 1, M + 1) FO (k, N)
            {
                if (mat[j - 1][k] == 1)
                {
                    act[j][k] = 1;
                    ++cnt;
                    FO (w, 5)
                    {
                        int p = j + dirs[w][0];
                        int q = k + dirs[w][1];
                        if (p < 1 || p >= M + 1 || q < 0 || q >= N)
                            continue;
                        mat[p][q] ^= 1;
                    }
                }
            }
            bool ok = true;
            FO (j, N)
                if (mat[M][j])
                    ok = false;
            if (ok)
            {
                string movs;
                FOR (j, 1, M + 1) FO (k, N)
                    movs.push_back(act[j][k]);
                if (cnt < mincnt)
                {
                    mincnt = cnt;
                    res = movs;
                }
                else if (cnt == mincnt)
                {
                    res = min(res, movs);
                }
            }
        }

        // ans
        if (res.size() == 0)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        FO (i, M)
        {
            printf("%d", (int)res[i * N]);
            FOR (j, 1, N)
                printf(" %d", (int)res[i * N + j]);
            printf("\n");
        }
    }
    return 0;
}