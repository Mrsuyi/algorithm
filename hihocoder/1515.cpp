#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int MAXN = 100100;

int N, M, Q;
int roots[MAXN];
int dists[MAXN] = {0};

int get_root(int a)
{
	if (roots[a] == a) return a;
	int nxt = roots[a];
	roots[a] = get_root(nxt);
	dists[a] += dists[nxt];
	return roots[a];
}

int main()
{
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; ++i)
		roots[i] = i;
	for (int i = 0; i < M; ++i)
	{
		int x, y, s, px, py;
		cin >> x >> y >> s;
		px = get_root(x);
		py = get_root(y);
		if (px == py) continue;
		if (s + dists[y] > dists[x])
		{
			roots[px] = py;
			dists[px] = -dists[x] + s + dists[y];
		}
		else
		{
			roots[py] = px;
			dists[py] = -dists[y] - s + dists[x];
		}
	}
	for (int i = 0; i < Q; ++i)
	{
		int x, y, px, py;
		cin >> x >> y;
		px = get_root(x);
		py = get_root(y);
		if (px != py)
			cout << -1 << endl;
		else
			cout << (dists[x] - dists[y]) << endl;
	}

    return 0;
};