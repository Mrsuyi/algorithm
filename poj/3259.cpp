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

bool tried[510];
bool in[510];
int cnt[510];
int val[510];

int main()
{
    int T;
    cin >> T;
    FOR (t, T)
    {
        int N, M, W;
        cin >> N >> M >> W;
        vector<vector<pii>> worms, paths;
        worms = paths = vector<vector<pii>>(N + 1, vector<pii>());
        FOR (i, M)
        {
            int from, to, time;
            cin >> from >> to >> time;
            paths[from].push_back(pii(to, time));
            paths[to].push_back(pii(from, time));
        }
        FOR (i, W)
        {
            int from, to, time;
            cin >> from >> to >> time;
            worms[from].push_back(pii(to, time));
        }
        memset(tried, 0, sizeof(tried));
        FOR (i, N)
        {
            int init = i + 1;
            if (tried[init]) continue;
            
            memset(cnt, 0, sizeof(cnt));
            memset(val, INT_MAX, sizeof(val));
            memset(in, 0, sizeof(in));
            queue<int> spfa;
            spfa.push(init);
            val[init] = 0;
            while (!spfa.empty())
            {
                int cur = spfa.front();
                spfa.pop();
                in[cur] = false;
                tried[cur] = true;
                if (++cnt[cur] > N)
                {
                    printf("YES\n");
                    goto end;
                }
                FOR (j, paths[cur].size())
                {
                    int to = paths[cur][j].fi;
                    int time = paths[cur][j].se;
                    int nval = val[cur] + time;
                    if (nval < val[to])
                    {
                        if (to == init)
                        {
                            printf("YES\n");
                            goto end;
                        }
                        val[to] = nval;
                        if (!in[to])
                        {
                            spfa.push(to);
                            in[to] = true;
                        }
                    }
                }
                FOR (j, worms[cur].size())
                {
                    int to = worms[cur][j].fi;
                    int time = worms[cur][j].se;
                    int nval = val[cur] - time;
                    if (nval < val[to])
                    {
                        if (to == init)
                        {
                            printf("YES\n");
                            goto end;
                        }
                        val[to] = nval;
                        if (!in[to])
                        {
                            spfa.push(to);
                            in[to] = true;
                        }
                    }
                }
            }
        }
        printf("NO\n");
        end:;
    }
    
    return 0;
}