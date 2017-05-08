#include <climits>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define fi first
#define se second
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define RFOR(i, n) for (int i = n - 1; i >= 0; --i)
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> pii;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

struct Item
{
	int price, level;
}
items[110];
vector<pii> edges[110];
int M, N;

int spfa(int lo)
{
	int hi = lo + M;
	bool in[110] = {0};
	int dp[110];
	queue<int> que;
	FOR (i, N)
	{
		dp[i + 1] = items[i + 1].price;
		if (items[i + 1].level >= lo && items[i + 1].level <= hi)
		{
			in[i + 1] = true;
			que.push(i + 1);
		}
	}
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		in[u] = false;
		FOR (i, edges[u].size())
		{
			int v = edges[u][i].fi;
			int price = edges[u][i].se;
			if (items[v].level < lo || items[v].level > hi)
				continue;
			if (dp[u] + price < dp[v])
			{
				dp[v] = dp[u] + price;
				if (!in[v])
				{
					que.push(v);
					in[v] = true;
				}
			}
		}
	}
	return dp[1];
}

int main()
{
	cin >> M >> N;
	FOR (i, N)
	{
		int P, L, X;
		cin >> P >> L >> X;
		items[i + 1].price = P;
		items[i + 1].level = L;
		FOR (j, X)
		{
			int id, price;
			cin >> id >> price;
			edges[id].push_back(pii(i + 1, price));
		}
	}
	int res = INT_MAX;
	for (int i = 0; i <= M; ++i)
		res = min(res, spfa(items[1].level - i));
	printf("%d\n", res);
	return 0;
}