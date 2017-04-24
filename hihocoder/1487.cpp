#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool has[1000][1000] = {0};
pair<int, int> roots[1000][1000];

pair<int, int> get_root(pair<int, int> pos)
{
	while (roots[pos.first][pos.second] != pos)
	{
		pos = roots[pos.first][pos.second];
	}
	return pos;
}

int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
	int N;
	cin >> N;
	int peri = 0, count = 0, area = 0;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		has[x][y] = true;
		vector<pair<int, int>> others;
		for (int j = 0; j < 4; ++j)
		{
			int p = x + dirs[j][0];
			int q = y + dirs[j][1];
			if (p >= 0 && p < 1000 && q >= 0 && q < 1000 && has[p][q])
				others.push_back(get_root({p, q}));
		}
		if (others.size() == 0)
		{
			roots[x][y] = {x, y};
			++count;
		}
		else if (others.size() == 1)
		{
			roots[x][y] = others[0];
		}
		else
		{
			roots[x][y] = {x, y};
			++count;
			for (int m = 0; m < others.size(); ++m)
			{
				bool dup = false;
				for (int n = 0; !dup && n < m; ++n)
					if (others[n] == others[m])
						dup = true;
				if (dup) continue;
				
				roots[others[m].first][others[m].second] = {x, y};
				--count;
			}
		}
		peri += 4 - 2 * others.size();
		++area;
		printf("%d %d %d\n", count, area, peri);
	}
	
	return 0;
}