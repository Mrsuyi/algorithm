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
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238463, EPS = 1e-8;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < EPS; }

vector<int> primes;
vector<int> cnt;
bool not_prime[10010] = {0};
int p, q, r, s;

void init()
{
    for (int i = 2; i * i < 10000; ++i) {
        if (not_prime[i]) continue;
        for (int j = i * i; j < 10000; j += i) {
            not_prime[j] = true;
        }
    }
    for (int i = 2; i < 10000; ++i)
        if (!not_prime[i]) primes.push_back(i);
}

void add_factor(int n, int k)
{
    for (size_t i = 0; i < primes.size(); ++i) {
        while (n % primes[i] == 0) {
            cnt[i] += k;
            n /= primes[i];
        }
        if (n == 1) break;
    }
}

void add_factorial(int n, int k)
{
    for (int i = 2; i <= n; ++i) add_factor(i, k);
}

int main()
{
    init();
    while (~scanf("%d %d %d %d", &p, &q, &r, &s)) {
        cnt = vector<int>(primes.size(), 0);
        add_factorial(p, 1);
        add_factorial(q, -1);
        add_factorial(p - q, -1);
        add_factorial(r, -1);
        add_factorial(s, 1);
        add_factorial(r - s, 1);
        double res = 1;
        for (size_t i = 0; i < primes.size(); ++i)
            if (cnt[i]) res *= pow(primes[i], cnt[i]);
        printf("%.5lf\n", res);
    }
    return 0;
}
