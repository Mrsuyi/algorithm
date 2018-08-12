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

bool not_prime[100010] = {0};
bool bad[100010];
vector<int> primes;
vector<pii> factors;

void init()
{
    for (int i = 2; i <= 1000; ++i) {
        if (not_prime[i]) continue;
        for (int j = i * i; j <= 100000; j += i) {
            not_prime[j] = true;
        }
    }
    for (int i = 2; i <= 100000; ++i) {
        if (!not_prime[i]) primes.push_back(i);
    }
}

int main()
{
    init();
    int n, m;
    while (~scanf("%d %d\n", &n, &m)) {
        --n;

        factors.clear();
        int mm = m;
        for (size_t i = 0; i < primes.size() && m != 1 && primes[i] <= mm;
             ++i) {
            if (m % primes[i] == 0) {
                factors.push_back({primes[i], 0});
                while (m % primes[i] == 0) {
                    ++factors.back().second;
                    m /= primes[i];
                }
            }
        }
        if (m != 1) factors.push_back({m, 1});

        memset(bad, 0, sizeof(bad));
        for (const pii& p : factors) {
            int prime = p.first;
            int need = p.second;
            int cnt = 0;
            for (int i = 1; i <= n / 2; ++i) {
                int x = n - i + 1;
                while (x % prime == 0) {
                    ++cnt;
                    x /= prime;
                }
                x = i;
                while (x % prime == 0) {
                    --cnt;
                    x /= prime;
                }
                if (cnt < need) {
                    bad[i] = true;
                }
            }
        }
        vector<int> res;
        for (int i = 1; i <= n / 2; ++i) {
            if (!bad[i]) {
                res.push_back(i);
            }
        }
        if (res.size()) {
            int i = res.size() - 1;
            if (res[i] * 2 == n) --i;
            for (; i >= 0; --i) res.push_back(n - res[i]);
            printf("%lu\n", res.size());
            printf("%d", res[0] + 1);
            for (size_t i = 1; i < res.size(); ++i) printf(" %d", res[i] + 1);
        } else {
            printf("0\n");
        }
        printf("\n");
    }
    return 0;
}
