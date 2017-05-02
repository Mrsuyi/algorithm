#include <climits>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef unsigned char byte;
typedef long long llong;
typedef unsigned long long ullong;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

pair<double, double> islands[1010];

int main()
{
	for (int t = 1, n, r; cin >> n >> r; ++t)
	{
		if (n == 0 && r == 0)
			break;
		bool ok = true;
		for (int i = 0; i < n; ++i)
		{
			double x, y;
			cin >> x >> y;
			if (y > r)
			{
				ok = false;
			}
			double delta = sqrt(r * r - y * y);
			islands[i].first = x + delta;
			islands[i].second = x - delta;
		}
		if (!ok)
		{
			printf("Case %d: -1\n", t);
			continue;
		}
		sort(islands, islands + n);
		int res = 0;
		double far = INT_MIN;
		for (int i = 0; i < n; ++i)
		{
			if (islands[i].second > far)
			{
				++res;
				far = islands[i].first;
			}
		}
		printf("Case %d: %d\n", t, res);
	}
    return 0;
};