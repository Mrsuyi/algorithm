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

int main()
{
    string s;
    cin >> s;
    int res = INT_MAX;
    int cnts[128] = {0};
    for (int i = 0, j = 0; i < s.size(); ++i)
    {
        ++cnts[s[i]];
        while (cnts['h'] > 2 || cnts['i'] > 1 || cnts['o'] > 1)
        {
            --cnts[s[j++]];
        }
        while (cnts['h'] == 2 && cnts['i'] == 1 && cnts['o'] == 1)
        {
            res = min(res, i - j + 1);
            --cnts[s[j++]];
        }
    }
    printf("%d\n", (res == INT_MAX) ? -1 : res);

    return 0;
};