#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

LL dist(const pair<LL, LL>& a, const pair<LL, LL>& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

LL dfs(const vector<pair<LL, LL>>& a, const vector<pair<LL, LL>>& b, vector<bool>& chosen, LL idx, LL sum)
{
    if (idx == a.size())
        return sum;
    LL res = LLONG_MAX;
    for (LL i = 0; i < b.size(); ++i)
    {
        if (chosen[i]) continue;
        chosen[i] = true;
        res = min(res, dfs(a, b, chosen, idx + 1, sum + dist(a[idx], b[i])));
        chosen[i] = false;
    }
    return res;
}

LL calc(const vector<pair<LL, LL>>& a, const vector<pair<LL, LL>>& b)
{
    LL res = 0;
    vector<bool> chosen(a.size(), false);
    return dfs(a, b, chosen, 0, 0);
}

int main()
{
    LL n, t;
    cin >> n >> t;
    vector<vector<pair<LL, LL>>> poss(t + 1, vector<pair<LL, LL>>(n));
    for (LL i = 0; i <= t; ++i)
    {
        for (LL j = 0; j < n; ++j)
            cin >> poss[i][j].first >> poss[i][j].second;
    }
    LL res = 0;
    for (LL i = 0; i < t; ++i)
        res += calc(poss[i], poss[i + 1]);
    cout << res << endl;
    system("PAUSE");
    return 0;
};