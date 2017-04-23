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

char chrs[3] = {'A', 'B', 'C'};

string proc(const string& s)
{
    string res;
    for (int i = 0; i < s.size();)
    {
        int j = i;
        while (j + 1 < s.size() && s[j + 1] == s[i]) ++j;
        if (i == j)
        {
            res.push_back(s[i]);
            ++i;
        }
        else
            i = j + 1;
    }
    return (res == s) ? res : proc(res);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        string s;
        cin >> s;
        
        int res = 0;
        for (int i = 0; i <= s.size(); ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                string ins = s.substr(0, i) + chrs[j] + s.substr(i);
                ins = proc(ins);
                res = max(res, (int)(s.size() - ins.size() + 1));
            }
        }
        cout << res << endl;
    }
    return 0;
};