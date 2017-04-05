#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

pair<int, long long> calc(const string& str)
{
    int q = 0, p = 0, max = 1;
    vector<int> least;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
        {
            ++q;
        }
        else
        {
            ++p;
            max = std::max(max, p - q);
            least.push_back(p - q);
        }
    }
    while (!least.empty() && least.back() < max)
        least.pop_back();
    
    if (least.empty()) return {0, 1};
    
    vector<long long> dp(max + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < least.size(); ++i)
    {
        vector<long long> tmp(max + 1, 0);
        
        for (int j = std::max(0, least[i]); j <= max; ++j)
        {
            for (int k = 0; k <= j; ++k)
                tmp[j] += dp[k];
            tmp[j] %= 1000000007;
        }
            
        std::swap(dp, tmp);
    }
    return {max, dp[max]};
}

int main()
{
    string str;
    cin >> str;
    
    auto a = calc(str);
    std::reverse(str.begin(), str.end());
    for (char& c : str)
        c = c == '(' ? ')' : '(';
    auto b = calc(str);
    cout << a.first + b.first << " " << a.second * b.second % 1000000007;
    
    return 0;
}