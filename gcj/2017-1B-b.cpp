#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

enum Color
{
	R = 0, G, B, O, Y, V
};
char c2c[6] = { 'R', 'G', 'B', 'O', 'Y', 'V' };

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int N;
		int cnts[6] = { 0 };
		cin >> N;
		cin >> cnts[R] >> cnts[O] >> cnts[Y] >> cnts[G] >> cnts[B] >> cnts[V];
		if (cnts[O] == cnts[B] && N == 2 * cnts[O])
		{
			string res;
			for (int i = 0; i < cnts[O]; ++i)
				res += "OB";
			printf("Case #%d: %s\n", t, res.data());
		}
		else if (cnts[G] == cnts[R] && N == 2 * cnts[G])
		{
			string res;
			for (int i = 0; i < cnts[G]; ++i)
				res += "GR";
			printf("Case #%d: %s\n", t, res.data());
		}
		else if (cnts[V] == cnts[Y] && N == 2 * cnts[V])
		{
			string res;
			for (int i = 0; i < cnts[V]; ++i)
				res += "VY";
			printf("Case #%d: %s\n", t, res.data());
		}
		else
		{
			cnts[B] -= cnts[O];
			cnts[R] -= cnts[G];
			cnts[Y] -= cnts[V];
			if ((cnts[O] != 0 && cnts[B] <= 0) ||
				(cnts[G] != 0 && cnts[R] <= 0) ||
				(cnts[V] != 0 && cnts[Y] <= 0))
			{
				printf("Case #%d: IMPOSSIBLE\n", t);
				continue;
			}
			vector<pair<int, int>> ryb = { {cnts[R], R}, {cnts[Y], Y}, {cnts[B], B} };
			sort(ryb.begin(), ryb.end(), [](const pair<int, int>& a, const pair<int, int>& b)
			{
				return a.first > b.first;
			});
			if (ryb[0].first > ryb[1].first + ryb[2].first)
			{
				printf("Case #%d: IMPOSSIBLE\n", t);
				continue;
			}
			string res;
			while (ryb[0].first > ryb[2].first)
			{
				res += c2c[ryb[0].second];
				res += c2c[ryb[1].second];
				--ryb[0].first;
				--ryb[1].first;
			}
			while (ryb[0].first > ryb[1].first)
			{
				res += c2c[ryb[0].second];
				res += c2c[ryb[2].second];
				--ryb[0].first;
			}
			while (ryb[0].first > 0)
			{
				res += c2c[ryb[0].second];
				res += c2c[ryb[1].second];
				res += c2c[ryb[2].second];
				--ryb[0].first;
			}
			if (cnts[O])
			{
				string ins;
				for (int i = 0; i < cnts[O]; ++i)
					ins += "BO";
				res.insert(res.find('B'), ins);
			}
			if (cnts[G])
			{
				string ins;
				for (int i = 0; i < cnts[G]; ++i)
					ins += "RG";
				res.insert(res.find('R'), ins);
			}
			if (cnts[V])
			{
				string ins;
				for (int i = 0; i < cnts[V]; ++i)
					ins += "YV";
				res.insert(res.find('Y'), ins);
			}
			printf("Case #%d: %s\n", t, res.data());
		}
	}
	return 0;
};