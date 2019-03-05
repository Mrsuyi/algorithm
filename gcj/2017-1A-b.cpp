#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N, P;
		cin >> N >> P;
		vector<int> ings(N);
		vector<vector<int>> pacs(N, vector<int>(P));
		for (int i = 0; i < N; ++i)
			cin >> ings[i];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < P; ++j)
				cin >> pacs[i][j];
		for (int i = 0; i < N; ++i)
			std::sort(pacs[i].begin(), pacs[i].end());
		int res = 0;
		vector<int> idxs(N, 0);
		for (int i = 0; i < P; ++i)
		{
			// get serving from first ingredient
			int smin = std::ceil(pacs[0][i] / (1.1 * ings[0]));
			int smax = std::floor(pacs[0][i] / (0.9 * ings[0]));
			bool ok = false, end = false;
			for (int s = smin; !ok && !end && s <= smax; ++s)
			{
				// try get compatible kits of other ingredients
				ok = true;
				for (int j = 1; j < N; ++j)
				{
					double min = ings[j] * s * 0.9;
					double max = ings[j] * s * 1.1;
					while (idxs[j] < P && pacs[j][idxs[j]] < min) ++idxs[j];
					if (idxs[j] == P || pacs[j][idxs[j]] > max)
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
			{
				++res;
				for (int j = 1; j < N; ++j)
					++idxs[j];
			}
		}
		printf("Case #%d: %d\n", t + 1, res);
	}
	return 0;
}