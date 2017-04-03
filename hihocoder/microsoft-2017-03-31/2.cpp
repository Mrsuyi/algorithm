#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	
	// input

	// count of nodes in one level
	vector<int> level(M);
	// nodes name
	vector<vector<int>> nodes(M);
	// if node is leaf
	vector<bool> is_leaf(N + 1, false);
	// distance between nodes
	vector<vector<int>> dists(N + 1, vector<int>(N + 1, 0));
	// parent of nodes
	vector<int> parents(N + 1, 0);
	// leaves
	vector<int> leaves;
	// foot
	vector<pair<int, int>> foots(N + 1);

	for (int i = 0; i < M; ++i)
		cin >> level[i];
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < level[i]; ++j)
		{
			int num;
			cin >> num;
			nodes[i].push_back(num);
		}
	for (int i = 0; i < K; ++i)
	{
		int num;
		cin >> num;
		is_leaf[num] = true;
		foots[num] = { num, 0 };
		leaves.push_back(num);
	}
	for (int i = 0; i < K; ++i)
	for (int j = 0; j < K; ++j)
	{
		int dist;
		cin >> dist;
		dists[leaves[i]][leaves[j]] = dists[leaves[j]][leaves[i]] = dist;
	}

	// process
	for (int i = M - 1; i > 0; --i)
	{
		int iparent = 0;
		while (is_leaf[nodes[i - 1][iparent]]) ++iparent;

		for (int j = 0; j < nodes[i].size(); ++j)
		{
			int cur = nodes[i][j];
			int parent = nodes[i - 1][iparent];

			// first node in that level
			if (j == 0)
			{
				parents[cur] = parent;
				foots[parent] = foots[cur];
				++foots[parent].second;
			}
			else
			{
				int pre = nodes[i][j - 1];

				pair<int, int> prefoot = foots[pre];
				pair<int, int> curfoot = foots[cur];
				int dist = dists[curfoot.first][prefoot.first] - curfoot.second - prefoot.second;
				
				if (dist == 2)
				{
					parents[cur] = parent;
					foots[parent] = foots[cur];
					++foots[parent].second;
				}
				else
				{
					int iparent2 = iparent + 1;
					while (is_leaf[nodes[i - 1][iparent2]]) ++iparent2;

					int newparent = nodes[i - 1][iparent2];

					parents[cur] = newparent;
					foots[newparent] = foots[cur];
					++foots[newparent].second;

					iparent = iparent2;
				}
			}
		}
	}

	// output
	cout << parents[1];
	for (int i = 2; i <= N; ++i)
		cout << " " << parents[i];

	return 0;
}