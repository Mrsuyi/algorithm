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

double A[10][31];
int B[10][31];

int main()
{
    FO (i, 10)
    {
        double m = 1 - pow(2, -(i + 1));
        FOR (j, 1, 31)
        {
            int exp = (1 << j) - 1;
            double lg = log10(m) + exp * log10(2);
            double intval = floor(lg);
            double decval = lg - intval;
            A[i][j] = pow(10, decval);
            B[i][j] = intval;
        }
    }

    string s;
    while (cin >> s)
    {
        if (s == "0e0")
            break;
        double a = stod(s.substr(0, s.find('e')));
        double b = stod(s.substr(s.find('e') + 1));
        while (a >= 10.0)
        {
            a /= 10.0;
            b += 1.0;
        }
        int M, E;
        double diff = DBL_MAX;
        FO (i, 10)
        FOR (j, 1, 31)
        {
            if (B[i][j] == b && abs(A[i][j] - a) < diff)
            {
                M = i;
                E = j;
                diff = abs(A[i][j] - a);
            }
        }
        printf("%d %d\n", M, E);
    }
    return 0;
}