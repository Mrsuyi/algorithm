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

string lower(const string& s)
{
    string res = s;
    for (int i = 0; i < res.size(); ++i)
        res[i] = tolower(res[i]);
    return res;
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        string res;
        string low = lower(s);
        size_t l = 0, r = 0;
        while ((r = low.find("marshtomp", l)) != string::npos)
        {
            res += s.substr(l, r - l);
            res += "fjxmlhx";
            l = r + sizeof("marshtomp") - 1;
        }
        if (l < s.size())
            res += s.substr(l);
        cout << res << endl;
    }
    return 0;
};