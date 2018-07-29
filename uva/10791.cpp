#include <algorithm>
#include <array>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
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
#ifdef __GNUC__
#if __cplusplus > 199711L
#include <unordered_map>
#include <unordered_set>
#else
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#endif
#else
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define FO(x, n) for (int x = 0; x < n; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

int N;
vector<int> primes;
bool not_prime[1 << 16] = {0};

void init()
{
    for (uint i = 2; i < (1 << 16); ++i) {
        if (not_prime[i]) continue;
        for (uint j = i * i; j < (1 << 16); j += i) not_prime[j] = true;
    }
    for (uint i = 2; i < (1 << 16); ++i)
        if (!not_prime[i]) {
            primes.push_back(i);
        }
}

int main()
{
    init();
    for (int o = 1; ~scanf("%d", &N) && N; ++o) {
        llong res = 0, cnt = 0;
        for (int i = 0; i < primes.size() && N > 1; ++i) {
            if (N % primes[i] == 0) {
                ++cnt;
                int factor = 1;
                while (N % primes[i] == 0) {
                    factor *= primes[i];
                    N /= primes[i];
                }
                res += factor;
            }
        }
        if (N > 1) {
            res += N;
            ++cnt;
        }
        if (cnt == 1)
            ++res;
        else if (cnt == 0)
            res = 2;
        printf("Case %d: %lld\n", o, res);
    }
    return 0;
}
