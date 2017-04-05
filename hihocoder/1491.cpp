#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1 << 20][5] = {0};
struct Monster
{
    int h, a;
    bool s;
    Monster() : h(-1) {}
    Monster(int h, int a, bool s) : h(h), a(a), s(s) {}
};
Monster monsters[6][6];
int N, M;
int dx, dy;
int mya;
int res = -1;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int mark(int status, int x, int y)
{
    status |= 1 << (x * N + y);
}
bool marked(int status, int x, int y)
{
    return status & (1 << (x * N + y));
}
bool valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

void dfs(int status, int h, int round, int moncnt)
{
    if (dp[status][round] >= h)
        return;
    dp[status][round] = h;
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!marked(status, i, j))
            {
                bool ok = false;
                for (int k = 0; k < 4 && !ok; ++k)
                {
                    int p = i + dirs[k][0];
                    int q = j + dirs[k][1];
                    ok = valid(p, q) && marked(status, p, q);
                }
                if (!ok) continue;
                
                if (monsters[i][j].h != -1)
                {
                    int r = round - 1;
                    int myh = h;
                    for (int monh = monsters[i][j].h; monh > 0; monh -= mya)
                    {
                        if (r > 0) --r;
                        else myh -= monsters[i][j].a;
                    }
                    if (myh > 0)
                    {
                        int s = status;
                        mark(s, i, j);
                        if (--moncnt == 0)
                            res = std::max(res, myh);
                        else
                            dfs(s, myh, monsters[i][j].s ? 5 : r, moncnt - 1);
                    }
                }
                else
                {
                    int s = status;
                    mark(s, i, j);
                    dfs(s, h, std::max(0, round - 1), moncnt);
                }
            }
}

int main()
{
    cin >> N >> M;
    int moncnt = 0;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            if (str[j] == 'S' || str[j] == 'M')
            {
                monsters[i][j].h = 1;
                monsters[i][j].s = str[j] == 'S';
                ++moncnt;
            }
            else if (str[j] == 'D')
            {
                dx = i;
                dy = j;
            }
        }
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (monsters[i][j].h != -1)
                cin >> monsters[i][j].h >> monsters[i][j].a;
    int myh;
    cin >> myh >> mya;
    
    int status = 0;
    mark(status, dx, dy);
    dfs(status, myh, 5, moncnt);
    
    if (res == -1)
        cout << "DEAD" << endl;
    else
        cout << res << endl;

	return 0;
}