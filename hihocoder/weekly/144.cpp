#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> divisors(long long n)
{
    vector<int> res;
    int end = std::ceil(std::sqrt(n));
    for (int i = 1; i < end; ++i)
        if (n % i == 0)
        {
            res.push_back(i);
            res.push_back(n / i);
        }
    if (end * end == n)
        res.push_back(end);
    std::sort(res.begin(), res.end());
    return res;
}

int gcd(int a, int b)
{
    if (b > a) return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    long long N, M;
    cin >> N >> M;
    
    int res = 0;
    auto dn = divisors(N);
    auto dm = divisors(M);
    for (int i = 0, j = 0; i < dn.size() && j < dm.size();)
    {
        if (dn[i] == dm[j])
        {
            ++res;
            ++i;
            ++j;
        }
        else if (dn[i] > dm[j])
            ++j;
        else
            ++i;
    }
    int total = dn.size() * dm.size();
    int g = gcd(total, res);
    res /= g;
    total /= g;
    cout << total << " " << res << endl;
    
    return 0;
}