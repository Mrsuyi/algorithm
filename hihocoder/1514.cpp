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

int main()
{
	int N, M, L;
	LL res = LLONG_MAX;
	cin >> N >> M >> L;
	set<LL> a, b;
	for (int i = 0; i < N; ++i)
	{
		LL num;
		cin >> num;
		a.insert(num);
	}
	for (int i = 0; i < M; ++i)
	{
		LL num;
		cin >> num;
		b.insert(num);
	}
	for (int i = 0; i < L; ++i)
	{
		LL num;
		cin >> num;
		auto al = a.lower_bound(num), ar = a.upper_bound(num);
		auto bl = b.lower_bound(num), br = b.upper_bound(num);
		if ((al != a.end() && *al > num) || al == a.end())
			--al;
		if ((bl != b.end() && *bl > num) || bl == b.end())
			--bl;

		if (al != a.end() && bl != b.end())
			res = min(res, abs(*al - *bl) + abs(*al - num) + abs(*bl - num));
		if (al != a.end() && br != b.end())
			res = min(res, abs(*al - *br) + abs(*al - num) + abs(*br - num));
		if (ar != a.end() && bl != b.end())
			res = min(res, abs(*ar - *bl) + abs(*ar - num) + abs(*bl - num));
		if (ar != a.end() && br != b.end())
			res = min(res, abs(*ar - *br) + abs(*ar - num) + abs(*br - num));
	}
	cout << res << endl;

	return 0;
};