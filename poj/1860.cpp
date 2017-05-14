#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define fi first
#define se second
#define FOR(x, n) for (int x = 0; x < n; ++x)
#define RFOR(x, n) for (int x = n - 1; x >= 0; --x)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llong, llong> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

const int MAXN = 220;

struct Edge
{
    int v, nxt;
    double r, c;
} edges[MAXN];
int tot = 1;
int head[MAXN] = {0};

void add_edge(int a, int b, double r, double c)
{
    edges[tot].v = b;
    edges[tot].r = r;
    edges[tot].c = c;
    edges[tot].nxt = head[a];
    head[a] = tot++;
}

int main()
{
    int N, M, S;
    double V;
    cin >> N >> M >> S >> V;
    FOR (i, M)
    {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        add_edge(a, b, rab, cab);
        add_edge(b, a, rba, cba);
    }
    int cnt[MAXN] = {0};
    bool in[MAXN] = {0};
    double dis[MAXN] = {0};
    queue<int> que;
    que.push(S);
    dis[S] = V;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        in[cur] = false;
        if (++cnt[cur] > N)
        {
            printf("YES\n");
            goto end;
        }
        for (int j = head[cur]; j != 0; j = edges[j].nxt)
        {
            int v = edges[j].v;
            double val = (dis[cur] - edges[j].c) * edges[j].r;
            if (val > dis[v])
            {
                if (v == S)
                {
                    printf("YES\n");
                    goto end;
                }
                dis[v] = val;
                if (!in[v])
                {
                    que.push(v);
                    in[v] = true;
                }
            }
        }
    }
    printf("NO\n");
    end:;
    return 0;
}