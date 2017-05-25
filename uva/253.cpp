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

string rotatex(const string& s)
{
    string a = s;
    char tmp = a[0];
    a[0] = a[1];
    a[1] = a[5];
    a[5] = a[4];
    a[4] = tmp;
    return a;
}

string rotatey(const string& s)
{
    string a = s;
    char tmp = a[1];
    a[1] = a[3];
    a[3] = a[4];
    a[4] = a[2];
    a[2] = tmp;
    return a;
}

string rotatez(const string& s)
{
    string a = s;
    char tmp = a[0];
    a[0] = a[3];
    a[3] = a[5];
    a[5] = a[2];
    a[2] = tmp;
    return a;   
}

int main()
{
    string s;
    while (cin >> s)
    {
        string a = s.substr(0, 6);
        string b = s.substr(6);
        FO (i, 4)
        {
            a = rotatex(a);
            string tmp = a;
            FO (j, 4)
            {
                tmp = rotatey(tmp);
                string tmp2 = tmp;
                FO (k, 4)
                {
                    tmp2 = rotatez(tmp2);
                    if (tmp == b)
                    {
                        printf("TRUE\n");
                        goto end;
                    }
                }
            }
        }
        printf("FALSE\n");
        end:;
    }
    return 0;
}