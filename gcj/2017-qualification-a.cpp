#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        string s;
        int k;
        cin >> s >> k;
        
        int l = 0, r = s.size() - 1;
        while (l <= r && s[l] == '+') ++l;
        while (l <= r && s[r] == '+') --r;
        int res = 0;
        for (; r - l + 1 >= k; ++res)
        {
            for (int j = 0; j < k; ++j)
                s[l + j] = s[l + j] == '-' ? '+' : '-';
            while (l <= r && s[l] == '+') ++l;
        }
        if (l != k + 1)
            printf("Case #%d: IMPOSSIBLE\n", i);
        else
            printf("Case #%d: %d\n", i, res);
    }
    
    return 0;
}