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
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

string bin2str(ullong num)
{
    string res;
    RFO (i, 4)
        res += to_string((num & (255ULL << (i * 8))) >> (i * 8)) + '.';
    res.pop_back();
    return res;
}

int main()
{
    int M;
    while (cin >> M)
    {
        bool init = false;
        ullong net;
        int len = 0;
        FO (i, M)
        {
            string s;
            cin >> s;
            ullong cur = 0;
            size_t pos = 0;
            FO (j, 4)
            {
                size_t nxt = s.find('.', pos);
                int num = stoi(s.substr(pos, nxt - pos));
                cur <<= 8;
                cur |= num;
                pos = nxt + 1;
            }
            if (!init)
            {
                init = true;
                net = cur;
            }
            RFOR (j, len, 32)
            {
                if ((net & (1ULL << j)) ^ (cur & (1ULL << j)))
                {
                    len = j + 1;
                    break;
                }
            }
        }
        ullong mask = ~((1ULL << len) - 1);
        net &= mask;
        cout << bin2str(net) << endl;
        cout << bin2str(mask) << endl;
    }
    return 0;
}