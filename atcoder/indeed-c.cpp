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

int n, m;
bool no[8][8] = {0};
bool conn[8][8] = {0};

bool check()
{
    bool conn2[8][8];
    memcpy(conn2, conn, sizeof(conn));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                if (conn2[j][i] && conn2[i][k])
                    conn2[j][k] = conn2[k][j] = true;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (!conn2[i][j])
                return false;
    return true;
}

LL dfs(int i1, int i2)
{
    if (i1 >= n)
        return check() ? 1 : 0;
    if (i2 >= n)
    {
        return dfs(i1 + 1, i1 + 2);
    }
    LL res = 0;
    res += dfs(i1, i2 + 1);
    if (!no[i1][i2])
    {
        conn[i1][i2] = conn[i2][i1] = true;
        res += dfs(i1, i2 + 1);
        conn[i1][i2] = conn[i2][i1] = false;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        no[a][b] = no[b][a] = true;
    }
    cout << dfs(0, 1) << endl;
    system("PAUSE");
    return 0;
};