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
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        string str;
        cin >> str;
        size_t pos = str.find('A');
        if (pos != string::npos)
            pos = str.find('A', pos + 1);
        size_t pos2 = str.find("LLL");
        printf("%s\n", (pos == string::npos && pos2 == string::npos) ? "YES" : "NO");
    }
    return 0;
};