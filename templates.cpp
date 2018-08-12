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

// a > b
// gcd of a/b
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// a > b
// d = gcd(a, b), a * x + b * y = d
void exgcd(int a, int b, int& d, int& x, int& y)
{
    if (b) {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    } else {
        d = a, x = 1, y = 0;
    }
}

// Eratosthenes filtering
// get all primes in [0, n]
bool not_prime[10000] = {0};
vector<int> primes;
void get_primes(int n)
{
    int m = sqrt(n + 0.5);
    for (int i = 2; i <= m; ++i) {
        if (not_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) not_prime[j] = true;
    }
    for (int i = 2; i <= n; ++i)
        if (!not_prime[i]) primes.push_back(i);
}

// unique prime-factorization theorem
vector<pii> factorize(int n)
{
    vector<pii> res;
    for (size_t i = 0; i < primes.size() && primes[i] <= n && n > 1; ++i) {
        if (n % primes[i] == 0) {
            res.push_back({primes[i], 0});
            while (n % primes[i] == 0) {
                ++res.back().second;
                n /= primes[i];
            }
        }
    }
    if (n > 1) res.push_back({n, 1});
    return res;
}

int main() { return 0; }
