#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll an2(ll n)
{
	return n * (n - 1);
}

ll cn2(ll n)
{
	return n * (n - 1) / 2;
}

int main()
{
	int N;
	cin >> N;
	vector<int> parents(N + 1, -1);
	vector<pair<int, int>> edges(N);
	parents[1] = 1;
	unordered_set<int> error;
	for (int i = 0; i < N; ++i)
	{
		cin >> edges[i].first >> edges[i].second;
		int a = edges[i].first;
		int b = edges[i].second;
		if (parents[b] == -1)
			parents[b] = a;
		else
			error.insert(b);
	}
	for (int i = 0; i < N; ++i)
	{
		if (error.count(edges[i].second))
			cout << i + 1 << " ";
	}

	return 0;
}