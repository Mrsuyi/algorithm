#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool dfs(vector<int>& colors, const vector<vector<int>>& neibs, int idx)
{
	if (idx == colors.size())
		return true;
	if (colors[idx] != 0)
		return dfs(colors, neibs, idx + 1);
	vector<int> tmp = colors;
	tmp[idx] = 1;
	queue<int> bfs;
	bfs.push(idx);
	bool ok = true;
	while (ok && !bfs.empty())
	{
		int u = bfs.front();
		bfs.pop();
		for (int v : neibs[u])
		{
			if (tmp[v] == 0)
			{
				tmp[v] = -tmp[u];
				bfs.push(v);
			}
			else if (tmp[v] != -tmp[u])
			{
				ok = false;
				break;
			}
		}
	}
	if (ok)
	{
		swap(colors, tmp);
		return dfs(colors, neibs, idx + 1);
	}
	else
		return false;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N, M;
		cin >> N >> M;
		vector<int> colors(N, 0);
		vector<vector<int>> neibs(N);
		for (int i = 0; i < M; ++i)
		{
			int u, v;
			cin >> u >> v;
			--u, --v;
			neibs[u].push_back(v);
			neibs[v].push_back(u);
		}
		if (dfs(colors, neibs, 0))
			cout << "Correct" << endl;
		else
			cout << "Wrong" << endl;
	}
	
    return 0;
};