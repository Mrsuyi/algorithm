#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
const int INF = 0x3f3f3f3f;

int N;
int in[MAXN];
int ip[MAXN];
int c[MAXN];
vector<int> children[MAXN];

int kill(int a)
{
	map<int, int> dp;
	dp[0] = 0;
	for (int child : children[a])
	{
		int cost = kill(child);
		if (cost == -1) continue;
		map<int, int> dp2 = dp;
		for (auto it = dp.begin(); it != dp.end(); ++it)
		{
			int info = it->first + ip[child];
			if (dp2.count(info))
				dp2[info] = min(dp2[info], it->second + cost);
			else
				dp2[info] = it->second + cost;
		}
		swap(dp, dp2);
	}
	int res = INT_MAX;
	for (auto it = dp.rbegin(); it != dp.rend() && it->first >= in[a]; ++it)
		res = min(res, it->second);
	return res == INT_MAX ? -1 : res + c[a];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int parent;
		cin >> parent >> in[i + 1] >> ip[i + 1] >> c[i + 1];
		children[parent].push_back(i + 1);
	}
	cout << kill(children[0][0]) << endl;
	system("PAUSE");
	return 0;
}