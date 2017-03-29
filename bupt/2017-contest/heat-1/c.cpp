#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

void solution()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > rs(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		rs[a].push_back(b);
		rs[b].push_back(a);
	}
	
	for (int i = 0; i < n; ++i)
	{
		int old = rs[i].size();
		set<int> fs;
		for (int j = 0; j < rs[i].size(); ++j)
		{
			int f = rs[i][j];
			fs.insert(f);
			for (int k = 0; k < rs[f].size(); ++k)
				fs.insert(rs[f][k]);
		}
		fs.erase(i);
		cout << (fs.size() - old) << endl;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
		solution();
	
	return 0;
}